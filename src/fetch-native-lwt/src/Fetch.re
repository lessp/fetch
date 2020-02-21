module IO = {
  module Response = {
    module Status = {
      include Fetch_Core.Response.Status;
    };

    module Headers = {
      include Fetch_Core.Headers;
    };

    module Body = {
      type t = Piaf.Body.t;

      let toString = body => {
        let bodyAsString = ref("");
        Lwt.Infix.(
          Piaf.Body.to_string(body)
          >|= (
            bodyString => {
              bodyAsString := bodyString;

              Lwt.return();
            }
          )
          |> ignore
        );
        bodyAsString^;
      };
      let ofString = body => Piaf.Body.of_string(body);
    };

    type t = {
      body: Body.t,
      headers: list(Headers.t),
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

  type t = Lwt.t(result(Response.t, string));

  let make = ({headers, body, meth, url}: Fetch_Core.Request.t) => {
    let body =
      switch (body) {
      | Some(body) => Piaf.Body.of_string(body)
      | None => Piaf.Body.empty
      };

    Lwt.Infix.(
      Piaf.Client.Oneshot.request(
        ~meth=Piaf.Method.of_string(Fetch_Core.Method.toString(meth)),
        ~headers=headers |> List.append([("User-Agent", "reason-fetch")]),
        ~body,
        url |> Uri.of_string,
      )
      >>= (
        res =>
          switch (res) {
          | Ok(response) =>
            Lwt.return(
              Ok(
                Response.make(
                  ~status=
                    Response.Status.make(
                      response |> Piaf.Response.status |> Piaf.Status.to_code,
                    ),
                  ~body=Piaf.Response.body(response),
                  ~headers=
                    Piaf.Response.headers(response) |> Piaf.Headers.to_list,
                  ~url,
                ),
              ),
            )
          | Error(error) => Lwt.return(Error(error))
          }
      )
    );
  };
};

include Fetch_Core.Fetchify.Make(IO);