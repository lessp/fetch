module Method = Method;
module Headers = Headers;
module Request = Request;
module Response = Response;

module type Sig = {
  type t;

  let make: Request.t => t;

  let fetch:
    (
      ~body: string=?,
      ~headers: list(Headers.t)=?,
      ~meth: Method.t=?,
      string,
      unit
    ) =>
    t;
};

module Make = (R: Sig) : (Sig with type t = R.t) => {
  type t = R.t;

  let make = R.make;

  let fetch = (~body=?, ~headers=[], ~meth=`GET, url, ()) =>
    Request.create(~body, ~headers, ~meth, ~url) |> make;
};

module Cohttp = {
  open Lwt.Infix;

  module Lwt =
    Make({
      type t = Lwt.t(result(Response.t, exn));

      let make = (req: Request.t) => {
        let headers = Cohttp.Header.of_list(req.headers);
        let body =
          switch (req.body) {
          | Some(b) => Cohttp_lwt.Body.of_string(b)
          | _ => Cohttp_lwt.Body.empty
          };
        let meth = Cohttp.Code.method_of_string(req.meth |> Method.toString);
        let url = Uri.of_string(req.url);

        let body =
          Cohttp_lwt_unix.Client.call(~headers, ~body, meth, url)
          >>= (
            ((resp, body)) => {
              let status =
                resp
                |> Cohttp.Response.status
                |> Cohttp.Code.code_of_status
                |> Status.ofCode;

              let headers =
                resp |> Cohttp.Response.headers |> Cohttp.Header.to_list;

              let url = url |> Uri.to_string;

              body
              |> Cohttp_lwt.Body.to_string
              >|= (body => Ok(Response.make(~status, ~body, ~headers, ~url)));
            }
          );

        body;
      };

      let fetch = (~body=?, ~headers=[], ~meth=`GET, url, ()) =>
        Request.create(~body, ~headers, ~meth, ~url) |> make;
    });

  module Repromise =
    Make({
      type t = Repromise.t(result(Response.t, exn));
      let make = (req: Request.t) =>
        {
          let headers = Cohttp.Header.of_list(req.headers);
          let body =
            switch (req.body) {
            | Some(b) => Cohttp_lwt.Body.of_string(b)
            | _ => Cohttp_lwt.Body.empty
            };
          let meth =
            Cohttp.Code.method_of_string(req.meth |> Method.toString);
          let url = Uri.of_string(req.url);

          let body =
            Cohttp_lwt_unix.Client.call(~headers, ~body, meth, url)
            >>= (
              ((resp, body)) => {
                let status =
                  resp
                  |> Cohttp.Response.status
                  |> Cohttp.Code.code_of_status
                  |> Status.ofCode;
                let headers =
                  resp |> Cohttp.Response.headers |> Cohttp.Header.to_list;
                let url = url |> Uri.to_string;
                body
                |> Cohttp_lwt.Body.to_string
                >|= (body => Response.make(~status, ~body, ~headers, ~url));
              }
            );
          body;
        }
        |> Repromise_lwt.lwtToRepromise;

      let fetch = (~body=?, ~headers=[], ~meth=`GET, url, ()) =>
        Request.create(~body, ~headers, ~meth, ~url) |> make;
    });
};
