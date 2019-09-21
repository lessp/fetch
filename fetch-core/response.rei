module Status: (module type of Status);
module Body: (module type of Body);

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
