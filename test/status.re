open Fetch_core.Status;

module ToCode = {
  let informationToCode = () => {
    open Alcotest;

    check(int, "Continue", toCode(`Continue), 100);
    check(int, "SwitchingProtocols", toCode(`SwitchingProtocols), 101);
    check(int, "Processing", toCode(`Processing), 102);
  };

  let successToCode = () => {
    open Alcotest;

    check(int, "OK", toCode(`OK), 200);
    check(int, "Created", toCode(`Created), 201);
    check(int, "Accepted", toCode(`Accepted), 202);
    check(
      int,
      "NonAuthoritativeInformation",
      toCode(`NonAuthoritativeInformation),
      203,
    );
    check(int, "NoContent", toCode(`NoContent), 204);
    check(int, "ResetContent", toCode(`ResetContent), 205);
    check(int, "PartialContent", toCode(`PartialContent), 206);
    check(int, "MultiStatus", toCode(`MultiStatus), 207);
    check(int, "AlreadyReported", toCode(`AlreadyReported), 208);
    check(int, "IMUsed", toCode(`IMUsed), 226);
  };

  let redirectionToCode = () => {
    open Alcotest;

    check(int, "MultipleChoices", toCode(`MultipleChoices), 300);
    check(int, "MovedPermanently", toCode(`MovedPermanently), 301);
    check(int, "Found", toCode(`Found), 302);
    check(int, "SeeOther", toCode(`SeeOther), 303);
    check(int, "NotModified", toCode(`NotModified), 304);
    check(int, "UseProxy", toCode(`UseProxy), 305);
    check(int, "TemporaryRedirect", toCode(`TemporaryRedirect), 307);
    check(int, "PermanentRedirect", toCode(`PermanentRedirect), 308);
  };

  let clientErrorToCode = () => {
    open Alcotest;

    check(int, "BadRequest", toCode(`BadRequest), 400);
    check(int, "Unauthorized", toCode(`Unauthorized), 401);
    check(int, "PaymentRequired", toCode(`PaymentRequired), 402);
    check(int, "Forbidden", toCode(`Forbidden), 403);
    check(int, "NotFound", toCode(`NotFound), 404);
    check(int, "MethodNotAllowed", toCode(`MethodNotAllowed), 405);
    check(int, "NotAcceptable", toCode(`NotAcceptable), 406);
    check(
      int,
      "ProxyAuthenticationRequired",
      toCode(`ProxyAuthenticationRequired),
      407,
    );
    check(int, "RequestTimeout", toCode(`RequestTimeout), 408);
    check(int, "Conflict", toCode(`Conflict), 409);
    check(int, "Gone", toCode(`Gone), 410);
    check(int, "LengthRequired", toCode(`LengthRequired), 411);
    check(int, "PreconditionFailed", toCode(`PreconditionFailed), 412);
    check(int, "PayloadTooLarge", toCode(`PayloadTooLarge), 413);
    check(int, "UriTooLong", toCode(`UriTooLong), 414);
    check(int, "UnsupportedMediaType", toCode(`UnsupportedMediaType), 415);
    check(int, "RangeNotSatisfiable", toCode(`RangeNotSatisfiable), 416);
    check(int, "ExpectationFailed", toCode(`ExpectationFailed), 417);
    check(int, "ImATeapot", toCode(`ImATeapot), 418);
    check(int, "MisdirectedRequest", toCode(`MisdirectedRequest), 421);
    check(int, "UnprocessableEntity", toCode(`UnprocessableEntity), 422);
    check(int, "Locked", toCode(`Locked), 423);
    check(int, "FailedDependency", toCode(`FailedDependency), 424);
    check(int, "UpgradeRequired", toCode(`UpgradeRequired), 426);
    check(int, "PreconditionRequired", toCode(`PreconditionRequired), 428);
    check(int, "TooManyRequests", toCode(`TooManyRequests), 429);
    check(
      int,
      "RequestHeaderFieldsTooLarge",
      toCode(`RequestHeaderFieldsTooLarge),
      431,
    );
    check(
      int,
      "UnavailableForLegalReasons",
      toCode(`UnavailableForLegalReasons),
      451,
    );
  };

  let internalErrorToCode = () => {
    open Alcotest;

    check(int, "InternalServerError", toCode(`InternalServerError), 500);
    check(int, "NotImplemented", toCode(`NotImplemented), 501);
    check(int, "BadGateway", toCode(`BadGateway), 502);
    check(int, "ServiceUnavailable", toCode(`ServiceUnavailable), 503);
    check(int, "GatewayTimeout", toCode(`GatewayTimeout), 504);
    check(
      int,
      "HttpVersionNotSupported",
      toCode(`HttpVersionNotSupported),
      505,
    );
    check(int, "VariantAlsoNegotiates", toCode(`VariantAlsoNegotiates), 506);
    check(int, "InsufficientStorage", toCode(`InsufficientStorage), 507);
    check(int, "LoopDetected", toCode(`LoopDetected), 508);
    check(int, "NotExtended", toCode(`NotExtended), 510);
    check(
      int,
      "NetworkAuthenticationRequired",
      toCode(`NetworkAuthenticationRequired),
      511,
    );
  };
};

let toCodeTest =
  Alcotest.(
    ToCode.(
      "Status - toCode",
      [
        test_case("informational", `Quick, informationToCode),
        test_case("success", `Quick, successToCode),
        test_case("redirection", `Quick, redirectionToCode),
        test_case("clientError", `Quick, clientErrorToCode),
        test_case("internalError", `Quick, internalErrorToCode),
      ],
    )
  );

let () = {
  Alcotest.(run("Status", [toCodeTest]));
};