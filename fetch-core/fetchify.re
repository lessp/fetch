include S;

module Make =
       (IO: IO)
       : (FETCH with type t := IO.t and module Response = IO.Response) => {
  module Response = IO.Response;
  module Method = Method;
  module Headers = Headers;

  let fetch = (~body=?, ~headers=[], ~meth=`GET, url, ()) =>
    Request.create(~body, ~headers, ~meth, ~url) |> IO.make;
};
