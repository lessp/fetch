module IO = {
  module Response = {
    module Status = {
      include Fetch_Core.Response.Status;
    };

    module Headers = {
      include Fetch_Core.Headers;
    };

    module Body = {
      type t = Cohttp.Body.t;

      let toString = body => {
        switch (body) {
        | `String(body) => body
        | _ => ""
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

  let make = ({headers, body, meth, url}: Fetch_Core.Request.t) => {
    Lwt.Infix.(
      Cohttp.(
        Cohttp_lwt_unix.Client.call(
          ~headers=Header.of_list(headers),
          ~body={
            switch (body) {
            | Some(body) => Cohttp_lwt.Body.of_string(body)
            | None => Cohttp_lwt.Body.empty
            };
          },
          Code.method_of_string(Fetch_Core.Method.toString(meth)),
          Uri.of_string(url),
        )
      )
      >>= (
        ((resp, body)) => {
          let status =
            resp |> Cohttp.Response.status |> Cohttp.Code.code_of_status;

          let headers =
            resp |> Cohttp.Response.headers |> Cohttp.Header.to_list;

          body
          |> Cohttp_lwt.Body.to_string
          >|= (
            body =>
              Ok(
                Response.make(
                  ~status=Response.Status.make(status),
                  ~body=Cohttp.Body.of_string(body),
                  ~headers,
                  ~url,
                ),
              )
          );
        }
      )
    );
  };
};

include Fetch_Core.Fetchify.Make(IO);
