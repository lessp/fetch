module IO = {
  module Response = {
    module Status = {
      include Fetch_Core.Response.Status;
    };

    module Headers = {
      include Fetch_Core.Headers;
    };

    module Body = {
      type t = Morph.Response.body;

      let toString = body => {
        switch (body) {
        | `String(body) => body
        | _ => ""
        };
      };

      let ofString = body => `String(body);

      let to_string = toString;
      let of_string = ofString;
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

  let make = ({headers, body, meth, url}: Fetch_Core.Request.t) => {
    Lwt.Infix.(
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
      )
      |> Morph_client.handle
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
      )
    );
  };
};

include Fetch_Core.Fetchify.Make(IO);
