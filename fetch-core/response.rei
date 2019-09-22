module Status: (module type of Status);

type t = {
  body: Body.t,
  headers: list(Headers.t),
  status: Status.t,
  url: string,
};

let make:
  (
    ~body: Body.t,
    ~headers: list(Headers.t),
    ~status: Status.t,
    ~url: string
  ) =>
  t;
