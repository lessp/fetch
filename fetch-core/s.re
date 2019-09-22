module type Body = {
  type t;

  let toString: t => string;
  let ofString: string => t;
};

module type Response = {
  module Status: (module type of Status);
  module Body: Body;

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
};

module type IO = {
  module Response: Response;

  type t;

  let make: Request.t => t;
};

/* module type RESPONSE = { */
/*   module Body: (module type of Body); */
/*   module Status: (module type of Status); */

/*   type t = { */
/*     body: Body.t, */
/*     headers: list(Headers.t), */
/*     status: Status.t, */
/*     url: string, */
/*   }; */

/*   let make: */
/*     ( */
/*       ~body: Body.t, */
/*       ~headers: list(Headers.t), */
/*       ~status: Status.t, */
/*       ~url: string */
/*     ) => */
/*     t; */
/* }; */

module type FETCH = {
  type t;

  module Method = Method;
  module Headers = Headers;
  module Response: Response;

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
