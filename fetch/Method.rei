type standard = [
  | `CONNECT
  | `DELETE
  | `GET
  | `HEAD
  | `OPTIONS
  | `POST
  | `PUT
  | `TRACE
];

type t = [ standard | `Other(string)];

let ofString: string => t;
let toString: t => string;