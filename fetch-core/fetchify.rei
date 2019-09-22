include (module type of S);

module Make:
  (IO: IO) => FETCH with module Response = IO.Response;
