module Method = Method;
module Headers = Headers;
module Request = Request;
module Response = Response;

module type HttpImplementation = {
  module Response = Response;

  type t;

  let make: Request.t => t;
};

module type S = {
  module Method = Method;
  module Headers = Headers;
  module Response = Response;

  type t;

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

module Make = (HI: HttpImplementation) : (S with type t = HI.t) => {
  module Method = Method;
  module Headers = Headers;
  module Response = Response;

  type t = HI.t;

  let fetch = (~body=?, ~headers=[], ~meth=`GET, url, ()) =>
    Request.create(~body, ~headers, ~meth, ~url) |> HI.make;
};