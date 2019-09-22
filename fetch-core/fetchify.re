include S;

module Make =
       (IO: IO)
       : (FETCH with module Response = IO.Response) => {
  module Response = IO.Response;
  module Method = Method;
  module Headers = Headers;

  type t = IO.t
  let fetch = (~body=?, ~headers=[], ~meth=`GET, url, ()) =>
    Request.create(~body, ~headers, ~meth, ~url) |> IO.make;
};
