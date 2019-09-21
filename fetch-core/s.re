module type IO = {
  module Response: (module type of Response);

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
  module Response: (module type of Response);

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
