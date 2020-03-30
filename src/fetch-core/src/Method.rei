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

/** Returns a t from a string.

      {2 Examples}
      {[Method.ofString("GET") = `GET]}
      {[Method.ofString("NOT_A_STANDARD_METHOD") = `Other("NOT_A_STANDARD_METHOD")]}
  */
let ofString: string => t;

/** Returns the string-representation of a t.

      {2 Examples}
      {[Method.toString(`GET) = "GET"]}
      {[Method.toString(`Other("NOT_A_STANDARD_METHOD") = "NOT_A_STANDARD_METHOD"]}
  */
let toString: t => string;
