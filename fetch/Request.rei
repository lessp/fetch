type t = {
  body: option(string),
  headers: list(Headers.t),
  meth: Method.t,
  url: string,
};

let create:
  (
    ~body: option(string),
    ~headers: list(Headers.t),
    ~meth: Method.t=?,
    ~url: string
  ) =>
  t;