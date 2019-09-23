include (module type of S);

module Make:
  (IO: IO) => FETCH with type t = IO.t and module Response = IO.Response;
