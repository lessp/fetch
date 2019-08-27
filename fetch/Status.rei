/* OCaml uses Giraffe_case and the idiomatic way in ReasonML
   seems to lean towards PascalCase, which is conflicting.

   Can this be generalised, but still be able to provide
   the user with all the possible `status codes`?
   */
type informational = [ | `Continue | `SwitchingProtocols | `Processing];

type success = [
  | `OK
  | `Created
  | `Accepted
  | `NonAuthoritativeInformation
  | `NoContent
  | `ResetContent
  | `PartialContent
  | `MultiStatus
  | `AlreadyReported
  | `IMUsed
];

type redirection = [
  | `MultipleChoices
  | `MovedPermanently
  | `Found
  | `SeeOther
  | `NotModified
  | `UseProxy
  | `TemporaryRedirect
  | `PermanentRedirect
];

type clientError = [
  | `BadRequest
  | `Unauthorized
  | `PaymentRequired
  | `Forbidden
  | `NotFound
  | `MethodNotAllowed
  | `NotAcceptable
  | `ProxyAuthenticationRequired
  | `RequestTimeout
  | `Conflict
  | `Gone
  | `LengthRequired
  | `PreconditionFailed
  | `PayloadTooLarge
  | `UriTooLong
  | `UnsupportedMediaType
  | `RangeNotSatisfiable
  | `ExpectationFailed
  | `ImATeapot
  | `MisdirectedRequest
  | `UnprocessableEntity
  | `Locked
  | `FailedDependency
  | `UpgradeRequired
  | `PreconditionRequired
  | `TooManyRequests
  | `RequestHeaderFieldsTooLarge
  | `UnavailableForLegalReasons
];

type serverError = [
  | `InternalServerError
  | `NotImplemented
  | `BadGateway
  | `ServiceUnavailable
  | `GatewayTimeout
  | `HttpVersionNotSupported
  | `VariantAlsoNegotiates
  | `InsufficientStorage
  | `LoopDetected
  | `NotExtended
  | `NetworkAuthenticationRequired
];

type standard = [
  clientError
  | informational
  | redirection
  | serverError
  | success
];

type t = [ standard | `Other(int)];

let toCode: t => int;
let ofCode: int => t;

let isInformational: t => bool;
let isSuccessful: t => bool;
let isRedirect: t => bool;
let isClientError: t => bool;
let isServerError: t => bool;
let isError: t => bool;