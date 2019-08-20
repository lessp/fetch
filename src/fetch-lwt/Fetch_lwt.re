module Method = Fetch.Method;
module Headers = Fetch.Headers;
module Request = Fetch.Request;
module Response = Fetch.Response;

module Option = {
  let map = mapper =>
    fun
    | None => None
    | Some(x) => Some(mapper(x));

  let withDefault = default =>
    fun
    | None => default
    | Some(x) => x;
};

module Lwt = {
  type t = Lwt.t(result(Response.t, exn));

  let make = ({headers, body, meth, url}: Request.t) => {
    open Lwt.Infix;

    let body =
      body
      |> Option.map(Cohttp_lwt.Body.of_string)
      |> Option.withDefault(Cohttp_lwt.Body.empty);

    let response =
      Cohttp.(
        Cohttp_lwt_unix.Client.call(
          ~headers=Header.of_list(headers),
          ~body,
          Code.method_of_string(Method.toString(meth)),
          Uri.of_string(url),
        )
      )
      >>= (
        ((resp, body)) => {
          let status =
            resp
            |> Cohttp.Response.status
            |> Cohttp.Code.code_of_status
            |> Response.Status.ofCode;

          let headers =
            resp |> Cohttp.Response.headers |> Cohttp.Header.to_list;

          body
          |> Cohttp_lwt.Body.to_string
          >|= (body => Ok(Response.make(~status, ~body, ~headers, ~url)));
        }
      );

    response;
  };
};

Fetch.Make(Lwt);
