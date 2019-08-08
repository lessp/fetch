module Method = {
  type t = [ | `DELETE | `GET | `POST | `PUT | `Other(string)];

  let toString =
    fun
    | `DELETE => "DELETE"
    | `GET => "GET"
    | `POST => "POST"
    | `PUT => "PUT"
    | `Other(v) => v;
};

module Headers = {
  type t = (string, string);
};

module Options = {
  type t = {
    body: option(string),
    headers: list(Headers.t),
    meth: Method.t,
    url: string,
  };

  let create = (~body, ~headers, ~meth=`GET, url) => {
    body,
    headers,
    meth,
    url,
  };
};

module Response = {
  type t = {
    status: int,
    body: string,
  };

  let make = (~status, ~body) => {status, body};
};

let make = (opts: Options.t) => {
  let headers = Cohttp.Header.of_list(opts.headers);
  let body =
    switch (opts.body) {
    | Some(b) => Cohttp_lwt.Body.of_string(b)
    | _ => Cohttp_lwt.Body.empty
    };
  let meth = Cohttp.Code.method_of_string(opts.meth |> Method.toString);
  let url = Uri.of_string(opts.url);
  open Lwt.Infix;
  let body =
    Cohttp_lwt_unix.Client.call(~headers, ~body, meth, url)
    >>= (
      ((resp, body)) => {
        let status =
          resp |> Cohttp.Response.status |> Cohttp.Code.code_of_status;

        body
        |> Cohttp_lwt.Body.to_string
        >|= (body => Response.make(~status, ~body));
      }
    );

  body;
};

let fetch = (~body=?, ~headers=[], ~meth, url) =>
  Options.create(~body, ~headers, ~meth, url) |> make;

let delete = (~headers=[], url) =>
  Options.create(~meth=`DELETE, ~headers, url, ~body=None) |> make;

let get = (~headers=[], url) =>
  Options.create(~meth=`GET, ~headers, url, ~body=None) |> make;

let post = (~body=?, ~headers=[], url) =>
  Options.create(~meth=`POST, ~body, ~headers, url) |> make;

let put = (~body=?, ~headers=[], url) =>
  Options.create(~meth=`PUT, ~body, ~headers, url) |> make;

module Request = {
  module type Sig = {
    type t;

    let make: Options.t => t;
  };

  module Make = (R: Sig) : (Sig with type t = R.t) => {
    type t = R.t;

    let make = R.make;
  };
};

module Repromise = {
  module Repromise =
    Request.Make({
      type t = Repromise.t(result(Response.t, exn));

      let make = (opts: Options.t) =>
        make(opts) |> Repromise_lwt.lwtToRepromise;
    });

  let fetch = (~body=?, ~headers=[], ~meth, url) =>
    Options.create(~body, ~headers, ~meth, url) |> Repromise.make;

  let delete = (~headers=[], url) =>
    Options.create(~meth=`DELETE, ~headers, url, ~body=None) |> Repromise.make;

  let get = (~headers=[], url) =>
    Options.create(~meth=`GET, ~headers, url, ~body=None) |> Repromise.make;

  let post = (~body=?, ~headers=[], url) =>
    Options.create(~meth=`POST, ~body, ~headers, url) |> Repromise.make;

  let put = (~body=?, ~headers=[], url) =>
    Options.create(~meth=`PUT, ~body, ~headers, url) |> Repromise.make;
};

/* module RepromiseFetch = { */
/*   let fetch = (~body=?, ~headers=[], ~meth, url) => */
/*     Options.create(~body, ~headers, ~meth, url) */
/*     |> make */
/*     |> Repromise_lwt.lwtToRepromise; */

/*   let delete = (~headers=[], url) => */
/*     Options.create(~meth=`DELETE, ~headers, url, ~body=None) */
/*     |> make */
/*     |> Repromise_lwt.lwtToRepromise; */

/*   let get = (~headers=[], url) => */
/*     Options.create(~meth=`GET, ~headers, url, ~body=None) */
/*     |> make */
/*     |> Repromise_lwt.lwtToRepromise; */

/*   let post = (~body=?, ~headers=[], url) => */
/*     Options.create(~meth=`POST, ~body, ~headers, url) */
/*     |> make */
/*     |> Repromise_lwt.lwtToRepromise; */

/*   let put = (~body=?, ~headers=[], url) => */
/*     Options.create(~meth=`PUT, ~body, ~headers, url) */
/*     |> make */
/*     |> Repromise_lwt.lwtToRepromise; */
/* }; */
