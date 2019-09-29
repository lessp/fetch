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

let ofString =
  fun
  | "CONNECT" => `CONNECT
  | "DELETE" => `DELETE
  | "GET" => `GET
  | "HEAD" => `HEAD
  | "OPTIONS" => `OPTIONS
  | "POST" => `POST
  | "PUT" => `PUT
  | "TRACE" => `TRACE
  | s => `Other(s);

let toString =
  fun
  | `CONNECT => "CONNECT"
  | `DELETE => "DELETE"
  | `GET => "GET"
  | `HEAD => "HEAD"
  | `OPTIONS => "OPTIONS"
  | `POST => "POST"
  | `PUT => "PUT"
  | `TRACE => "TRACE"
  | `Other(v) => v;

let of_string = ofString;
let to_string = toString;
