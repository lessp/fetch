module IO = {
  module Response = {
    module Status = {
      include Fetch_core.Response.Status;
    };

    module Headers = {
      include Fetch_core.Headers;
    };

    module Body = {
      type t = Morph.Response.body;

      let toString = body => {
        switch (body) {
        | `String(body) => body
        | `Stream(chars) => Lwt_stream.to_string(chars) |> Lwt_main.run
        };
      };

      let ofString = body => `String(body);
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

  type t = Lwt.t(result(Response.t, exn));

  let make = ({headers, body, meth, url}: Fetch_core.Request.t) => {
    open Lwt.Infix;

    let morph_request =
      Morph.Request.make(
        ~meth,
        ~headers=headers |> List.append([("User-Agent", "reason-fetch")]),
        ~read_body=
          () =>
            Lwt.return(
              body
              |> (
                fun
                | None => ""
                | Some(body) => body
              ),
            ),
        url,
      );

    let response =
      Morph_client.handle(morph_request)
      >>= (
        ({Morph.Response.status, body, headers}) => {
          Lwt.return(
            Ok(
              Response.make(
                ~status=Response.Status.make(status |> Morph.Status.to_code),
                ~body,
                ~headers,
                ~url,
              ),
            ),
          );
        }
      );

    response;
  };
};

include Fetch_core.Fetchify.Make(IO);
