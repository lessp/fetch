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

/** Returns a code as an int from a t.

      {2 Examples}
      {[Status.toCode(`OK) = 200]}
      {[Status.toCode(`Other(999)) = 999]}
  */
let toCode: t => int;

/** Returns a t from an int.

      {2 Examples}
      {[Status.ofCode(200) = `OK]}
      {[Status.ofCode(999) = `Other(999)]}
  */
let ofCode: int => t;

/** Returns true if the status is informational.

      {2 Examples}
      {[Status.isInformational(`Continue) = true]}
      {[Status.isInformational(`NotFound) = false]}
      {[Status.isInformational(`OK) = false]}
  */
let isInformational: t => bool;

/** Returns true if the status is successful.

      {2 Examples}
      {[Status.isSuccessful(`OK) = true]}
      {[Status.isSuccessful(`InternalServerError) = false]}
  */
let isSuccessful: t => bool;

/** Returns true if the status is a redirect.

      {2 Examples}
      {[Status.isRedirect(`MovedPermanently) = true]}
      {[Status.isRedirect(`InternalServerError) = false]}
  */
let isRedirect: t => bool;

/** Returns true if the status is that of a client error.

      {2 Examples}
      {[Status.isClientError(`NotFound) = true]}
      {[Status.isClientError(`InternalServerError) = false]}
      {[Status.isClientError(`OK) = false]}
  */
let isClientError: t => bool;

/** Returns true if the status is that of a server error.

      {2 Examples}
      {[Status.isServerError(`InternalServerError) = true]}
      {[Status.isServerError(`NotFound) = false]}
      {[Status.isServerError(`OK) = false]}
  */
let isServerError: t => bool;

/** Returns true if the status is an error, either of type client or server.

      {2 Examples}
      {[Status.isError(`InternalServerError) = true]}
      {[Status.isError(`NotFound) = true]}
      {[Status.isError(`OK) = false]}
  */
let isError: t => bool;

let make: int => t;
