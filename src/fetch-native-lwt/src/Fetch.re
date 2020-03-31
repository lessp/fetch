module FetchImplementation = {
  module Headers = Fetch_Core.Headers;
  module Method = Fetch_Core.Method;
  module Status = Fetch_Core.Status;
  module Request = Fetch_Core.Request;

  type promise('a) = Lwt.t('a);
  type result('a, 'error) = Stdlib.Result.t('a, 'error);

  module Body = {
    type t = string;

    let make = body => body;

    let toString = body => body;
    let ofString = body => make(body);
  };

  module Response = {
    module Body = Body;
    module Status = Status;

    type t = {
      body: Body.t,
      headers: list(Fetch_Core.Headers.t),
      status: Status.t,
      url: string,
    };

    let make = (~body, ~headers, ~status, ~url) => {
      body,
      headers,
      status,
      url,
    };
  };

  let fetch = (~body=?, ~headers=[], ~meth=`GET, url) => {
    let {Fetch_Core.Request.headers, body, meth, url} =
      Fetch_Core.Request.create(~body, ~headers, ~meth, ~url);

    let body =
      switch (body) {
      | Some(body) => Piaf.Body.of_string(body)
      | None => Piaf.Body.empty
      };

    Lwt.Infix.(
      Piaf.Client.Oneshot.request(
        ~config={...Piaf.Config.default, follow_redirects: true},
        ~meth=Piaf.Method.of_string(Method.toString(meth)),
        ~headers=headers |> List.append([("User-Agent", "reason-fetch")]),
        ~body,
        url |> Uri.of_string,
      )
      >>= (
        res =>
          switch (res) {
          | Ok(response) =>
            Piaf.Response.body(response)
            |> Piaf.Body.to_string
            >>= (
              body =>
                Lwt.return(
                  Ok(
                    Response.make(
                      ~status=
                        Status.make(
                          Piaf.Response.status(response)
                          |> Piaf.Status.to_code,
                        ),
                      ~body=Body.make(body),
                      ~headers=
                        Piaf.Response.headers(response)
                        |> Piaf.Headers.to_list,
                      ~url,
                    ),
                  ),
                )
            )
          | Error(error) => Lwt.return(Error(error))
          }
      )
    );
  };
};

include Fetch_Core.Fetchify.CreateFetchImplementation(FetchImplementation);
