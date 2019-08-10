module Method: {
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
};

module Headers: {
  type name = string;
  type value = string;

  type t = (name, value);
};

module Request: {
  type t;

  let create:
    (
      ~body: option(string),
      ~headers: list(Headers.t),
      ~meth: Method.t=?,
      ~url: string
    ) =>
    t;
};

module Response: {
  module Body: {
    type t;

    let toString: t => string;
    let ofString: string => t;
  };

  module Status: {
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
  };

  type t = {
    body: Body.t,
    headers: list(Headers.t),
    status: Status.t,
    url: string,
  };

  let make:
    (
      ~body: Body.t,
      ~headers: list(Headers.t),
      ~status: Status.t,
      ~url: string
    ) =>
    t;
};

module type Sig = {
  type t;
  let make: Request.t => t;
  let fetch:
    (
      ~body: string=?,
      ~headers: list(Headers.t)=?,
      ~meth: Method.t=?,
      string
    ) =>
    t;
};

module Make:
  (R: Sig) =>
   {
    type t = R.t;
    let make: Request.t => t;
    let fetch:
      (
        ~body: string=?,
        ~headers: list(Headers.t)=?,
        ~meth: Method.t=?,
        string
      ) =>
      t;
  };

module Cohttp: {
  module Lwt: {
    type t = Lwt.t(result(Response.t, exn));
    let make: Request.t => t;
    let fetch:
      (
        ~body: string=?,
        ~headers: list(Headers.t)=?,
        ~meth: Method.t=?,
        string
      ) =>
      t;
  };

  module Repromise: {
    type t = Repromise.t(result(Response.t, exn));
    let make: Request.t => t;
    let fetch:
      (
        ~body: string=?,
        ~headers: list(Headers.t)=?,
        ~meth: Method.t=?,
        string
      ) =>
      t;
  };
};
