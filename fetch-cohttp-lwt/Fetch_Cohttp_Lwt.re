module CohttpLwt = {
  type t = Lwt.t(result(Fetch.Response.t, exn));
  let make = ({headers, body, meth, url}: Fetch.Request.t) => {
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
          Code.method_of_string(Fetch.Method.toString(meth)),
          Uri.of_string(url),
        )
      )
      >>= (
        ((resp, body)) => {
          let status =
            resp
            |> Cohttp.Response.status
            |> Cohttp.Code.code_of_status
            |> Fetch.Response.Status.ofCode;
          let headers =
            resp |> Cohttp.Response.headers |> Cohttp.Header.to_list;
          body
          |> Cohttp_lwt.Body.to_string
          >|= (
            body => Ok(Fetch.Response.make(~status, ~body, ~headers, ~url))
          );
        }
      );
    response;
  };
};

Fetch.Make(CohttpLwt);