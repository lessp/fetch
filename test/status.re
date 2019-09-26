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

  let otherToCode = () => {
    Alcotest.(check(int, "Other", toCode(`Other(666)), 666));
  };
};

module OfCode = {
  let informationOfCode = () => {
    open Alcotest;

    check(int, "Continue", 100 |> ofCode |> toCode, 100);
    check(int, "SwitchingProtocols", 101 |> ofCode |> toCode, 101);
    check(int, "Processing", 102 |> ofCode |> toCode, 102);
  };

  let successOfCode = () => {
    open Alcotest;

    check(int, "OK", 200 |> ofCode |> toCode, 200);
    check(int, "Created", 201 |> ofCode |> toCode, 201);
    check(int, "Accepted", 202 |> ofCode |> toCode, 202);
    check(int, "NonAuthoritativeInformation", 203 |> ofCode |> toCode, 203);
    check(int, "NoContent", 204 |> ofCode |> toCode, 204);
    check(int, "ResetContent", 205 |> ofCode |> toCode, 205);
    check(int, "PartialContent", 206 |> ofCode |> toCode, 206);
    check(int, "MultiStatus", 207 |> ofCode |> toCode, 207);
    check(int, "AlreadyReported", 208 |> ofCode |> toCode, 208);
    check(int, "IMUsed", 226 |> ofCode |> toCode, 226);
  };

  let redirectionOfCode = () => {
    open Alcotest;

    check(int, "MultipleChoices", 300 |> ofCode |> toCode, 300);
    check(int, "MovedPermanently", 301 |> ofCode |> toCode, 301);
    check(int, "Found", 302 |> ofCode |> toCode, 302);
    check(int, "SeeOther", 303 |> ofCode |> toCode, 303);
    check(int, "NotModified", 304 |> ofCode |> toCode, 304);
    check(int, "UseProxy", 305 |> ofCode |> toCode, 305);
    check(int, "TemporaryRedirect", 307 |> ofCode |> toCode, 307);
    check(int, "PermanentRedirect", 308 |> ofCode |> toCode, 308);
  };

  let clientErrorOfCode = () => {
    open Alcotest;

    check(int, "BadRequest", 400 |> ofCode |> toCode, 400);
    check(int, "Unauthorized", 401 |> ofCode |> toCode, 401);
    check(int, "PaymentRequired", 402 |> ofCode |> toCode, 402);
    check(int, "Forbidden", 403 |> ofCode |> toCode, 403);
    check(int, "NotFound", 404 |> ofCode |> toCode, 404);
    check(int, "MethodNotAllowed", 405 |> ofCode |> toCode, 405);
    check(int, "NotAcceptable", 406 |> ofCode |> toCode, 406);
    check(int, "ProxyAuthenticationRequired", 407 |> ofCode |> toCode, 407);
    check(int, "RequestTimeout", 408 |> ofCode |> toCode, 408);
    check(int, "Conflict", 409 |> ofCode |> toCode, 409);
    check(int, "Gone", 410 |> ofCode |> toCode, 410);
    check(int, "LengthRequired", 411 |> ofCode |> toCode, 411);
    check(int, "PreconditionFailed", 412 |> ofCode |> toCode, 412);
    check(int, "PayloadTooLarge", 413 |> ofCode |> toCode, 413);
    check(int, "UriTooLong", 414 |> ofCode |> toCode, 414);
    check(int, "UnsupportedMediaType", 415 |> ofCode |> toCode, 415);
    check(int, "RangeNotSatisfiable", 416 |> ofCode |> toCode, 416);
    check(int, "ExpectationFailed", 417 |> ofCode |> toCode, 417);
    check(int, "ImATeapot", 418 |> ofCode |> toCode, 418);
    check(int, "MisdirectedRequest", 421 |> ofCode |> toCode, 421);
    check(int, "UnprocessableEntity", 422 |> ofCode |> toCode, 422);
    check(int, "Locked", 423 |> ofCode |> toCode, 423);
    check(int, "FailedDependency", 424 |> ofCode |> toCode, 424);
    check(int, "UpgradeRequired", 426 |> ofCode |> toCode, 426);
    check(int, "PreconditionRequired", 428 |> ofCode |> toCode, 428);
    check(int, "TooManyRequests", 429 |> ofCode |> toCode, 429);
    check(int, "RequestHeaderFieldsTooLarge", 431 |> ofCode |> toCode, 431);
    check(int, "UnavailableForLegalReasons", 451 |> ofCode |> toCode, 451);
  };

  let internalErrorOfCode = () => {
    open Alcotest;

    check(int, "InternalServerError", 500 |> ofCode |> toCode, 500);
    check(int, "NotImplemented", 501 |> ofCode |> toCode, 501);
    check(int, "BadGateway", 502 |> ofCode |> toCode, 502);
    check(int, "ServiceUnavailable", 503 |> ofCode |> toCode, 503);
    check(int, "GatewayTimeout", 504 |> ofCode |> toCode, 504);
    check(int, "HttpVersionNotSupported", 505 |> ofCode |> toCode, 505);
    check(int, "VariantAlsoNegotiates", 506 |> ofCode |> toCode, 506);
    check(int, "InsufficientStorage", 507 |> ofCode |> toCode, 507);
    check(int, "LoopDetected", 508 |> ofCode |> toCode, 508);
    check(int, "NotExtended", 510 |> ofCode |> toCode, 510);
    check(int, "NetworkAuthenticationRequired", 511 |> ofCode |> toCode, 511);
  };

  let otherOfCode = () => {
    Alcotest.(check(int, "Other", 666 |> ofCode |> toCode, 666));
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
        test_case("other", `Quick, otherToCode),
      ],
    )
  );

let ofCodeTest =
  Alcotest.(
    OfCode.(
      "Status - ofCode",
      [
        test_case("informational", `Quick, informationOfCode),
        test_case("success", `Quick, successOfCode),
        test_case("redirection", `Quick, redirectionOfCode),
        test_case("clientError", `Quick, clientErrorOfCode),
        test_case("internalError", `Quick, internalErrorOfCode),
        test_case("other", `Quick, otherOfCode),
      ],
    )
  );

let () = {
  Alcotest.(run("Status", [toCodeTest, ofCodeTest]));
};
