type t = {
  body: option(string),
  headers: list(Headers.t),
  meth: Method.t,
  url: string,
};

let create = (~body, ~headers, ~meth=`GET, ~url) => {
  body,
  headers,
  meth,
  url,
};
