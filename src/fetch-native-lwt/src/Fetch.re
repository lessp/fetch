module IO = {
  module Response = {
    module Status = {
      include Fetch_Core.Response.Status;
    };

    module Headers = {
      include Fetch_Core.Headers;
    };

    module Body = {
      type t = string;

      let make = body => body;

      let toString = body => body;
      let ofString = body => body;
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
    let result =
      Lwt.Infix.(
        Piaf.(
          Client.Oneshot.request(
            ~config={...Piaf.Config.default, follow_redirects: true},
            ~headers,
            ~body={
              switch (body) {
              | Some(body) => Body.of_string(body)
              | None => Body.empty
              };
            },
            ~meth=Method.of_string(Fetch_Core.Method.toString(meth)),
            Uri.of_string(url),
          )
        )
        >>= (
          fun
          | Ok((resp, body)) => {
              let status = resp.status |> Piaf.Status.to_code;
              let headers = resp.headers |> Piaf.Headers.to_list;

              body
              |> Piaf.Body.to_string
              >>= (
                body =>
                  Lwt.return(
                    Ok(
                      Response.make(
                        ~status=Response.Status.make(status),
                        ~body=Response.Body.make(body),
                        ~headers,
                        ~url,
                      ),
                    ),
                  )
              );
            }
          | Error(e) => Lwt.return(Error(e))
        )
      );

    result;
  };
};

include Fetch_Core.Fetchify.Make(IO);
