module IO = {
  module Response = {
    module Status = {
      include Fetch_core.Response.Status;
    };

    module Body = {
      type t = Cohttp.Body.t;

      let toString = body => Cohttp.Body.to_string(body);
      let ofString = body => Cohttp.Body.of_string(body);
    };

    type t = {
      body: Body.t,
      headers: list(Fetch_core.Headers.t),
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

    let body =
      body
      |> Utils.Option.map(Cohttp_lwt.Body.of_string)
      |> Utils.Option.withDefault(Cohttp_lwt.Body.empty);

    let response =
      Cohttp.(
        Cohttp_lwt_unix.Client.call(
          ~headers=Header.of_list(headers),
          ~body,
          Code.method_of_string(Fetch_core.Method.toString(meth)),
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
      );
    response;
  };
};

include Fetch_core.Fetchify.Make(IO);
