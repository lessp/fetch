module Status = Status;
module Body = Body;

type t = {
  body: Body.t,
  headers: list(Headers.t),
  status: Status.t,
  url: string,
};

let make = (~body, ~headers, ~status, ~url) => {body, headers, status, url};
