module Method = Method;
module Headers = Headers;
module Request = Request;
module Response = Response;

module type ClientRequest = {
  type t;

  let make: Request.t => t;
};

module Make = (R: ClientRequest) => {
  type t = R.t;

  let fetch = (~body=?, ~headers=[], ~meth=`GET, url, ()) =>
    Request.create(~body, ~headers, ~meth, ~url) |> R.make;
};
