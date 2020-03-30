open TestFramework;
open Fetch_Core.Status;

describe("Status", ({describe, _}) => {
  describe("Informational", ({test, _}) => {
    test("toCode", ({expect, _}) => {
      expect.equal(toCode(`Continue), 100);
      expect.equal(toCode(`SwitchingProtocols), 101);
      expect.equal(toCode(`Processing), 102);
    });

    test("ofCode", ({expect, _}) => {
      expect.equal(100 |> ofCode |> toCode, 100);
      expect.equal(101 |> ofCode |> toCode, 101);
      expect.equal(102 |> ofCode |> toCode, 102);
    });
  });

  describe("Success", ({test, _}) => {
    test("toCode", ({expect, _}) => {
      expect.equal(toCode(`OK), 200);
      expect.equal(toCode(`Created), 201);
      expect.equal(toCode(`Accepted), 202);
      expect.equal(toCode(`NonAuthoritativeInformation), 203);
      expect.equal(toCode(`NoContent), 204);
      expect.equal(toCode(`ResetContent), 205);
      expect.equal(toCode(`PartialContent), 206);
      expect.equal(toCode(`MultiStatus), 207);
      expect.equal(toCode(`AlreadyReported), 208);
      expect.equal(toCode(`IMUsed), 226);
    });

    test("ofCode", ({expect, _}) => {
      expect.equal(200 |> ofCode |> toCode, 200);
      expect.equal(201 |> ofCode |> toCode, 201);
      expect.equal(202 |> ofCode |> toCode, 202);
      expect.equal(203 |> ofCode |> toCode, 203);
      expect.equal(204 |> ofCode |> toCode, 204);
      expect.equal(205 |> ofCode |> toCode, 205);
      expect.equal(206 |> ofCode |> toCode, 206);
      expect.equal(207 |> ofCode |> toCode, 207);
      expect.equal(208 |> ofCode |> toCode, 208);
      expect.equal(226 |> ofCode |> toCode, 226);
    });
  });

  describe("Redirection", ({test, _}) => {
    test("toCode", ({expect, _}) => {
      expect.equal(toCode(`MultipleChoices), 300);
      expect.equal(toCode(`MovedPermanently), 301);
      expect.equal(toCode(`Found), 302);
      expect.equal(toCode(`SeeOther), 303);
      expect.equal(toCode(`NotModified), 304);
      expect.equal(toCode(`UseProxy), 305);
      expect.equal(toCode(`TemporaryRedirect), 307);
      expect.equal(toCode(`PermanentRedirect), 308);
    });

    test("ofCode", ({expect, _}) => {
      expect.equal(300 |> ofCode |> toCode, 300);
      expect.equal(301 |> ofCode |> toCode, 301);
      expect.equal(302 |> ofCode |> toCode, 302);
      expect.equal(303 |> ofCode |> toCode, 303);
      expect.equal(304 |> ofCode |> toCode, 304);
      expect.equal(305 |> ofCode |> toCode, 305);
      expect.equal(307 |> ofCode |> toCode, 307);
      expect.equal(308 |> ofCode |> toCode, 308);
    });
  });

  describe("Client Error", ({test, _}) => {
    test("toCode", ({expect, _}) => {
      expect.equal(toCode(`BadRequest), 400);
      expect.equal(toCode(`Unauthorized), 401);
      expect.equal(toCode(`PaymentRequired), 402);
      expect.equal(toCode(`Forbidden), 403);
      expect.equal(toCode(`NotFound), 404);
      expect.equal(toCode(`MethodNotAllowed), 405);
      expect.equal(toCode(`NotAcceptable), 406);
      expect.equal(toCode(`ProxyAuthenticationRequired), 407);
      expect.equal(toCode(`RequestTimeout), 408);
      expect.equal(toCode(`Conflict), 409);
      expect.equal(toCode(`Gone), 410);
      expect.equal(toCode(`LengthRequired), 411);
      expect.equal(toCode(`PreconditionFailed), 412);
      expect.equal(toCode(`PayloadTooLarge), 413);
      expect.equal(toCode(`UriTooLong), 414);
      expect.equal(toCode(`UnsupportedMediaType), 415);
      expect.equal(toCode(`RangeNotSatisfiable), 416);
      expect.equal(toCode(`ExpectationFailed), 417);
      expect.equal(toCode(`ImATeapot), 418);
      expect.equal(toCode(`MisdirectedRequest), 421);
      expect.equal(toCode(`UnprocessableEntity), 422);
      expect.equal(toCode(`Locked), 423);
      expect.equal(toCode(`FailedDependency), 424);
      expect.equal(toCode(`UpgradeRequired), 426);
      expect.equal(toCode(`PreconditionRequired), 428);
      expect.equal(toCode(`TooManyRequests), 429);
      expect.equal(toCode(`RequestHeaderFieldsTooLarge), 431);
      expect.equal(toCode(`UnavailableForLegalReasons), 451);
    });

    test("ofCode", ({expect, _}) => {
      expect.equal(400 |> ofCode |> toCode, 400);
      expect.equal(401 |> ofCode |> toCode, 401);
      expect.equal(402 |> ofCode |> toCode, 402);
      expect.equal(403 |> ofCode |> toCode, 403);
      expect.equal(404 |> ofCode |> toCode, 404);
      expect.equal(405 |> ofCode |> toCode, 405);
      expect.equal(406 |> ofCode |> toCode, 406);
      expect.equal(407 |> ofCode |> toCode, 407);
      expect.equal(408 |> ofCode |> toCode, 408);
      expect.equal(409 |> ofCode |> toCode, 409);
      expect.equal(410 |> ofCode |> toCode, 410);
      expect.equal(411 |> ofCode |> toCode, 411);
      expect.equal(412 |> ofCode |> toCode, 412);
      expect.equal(413 |> ofCode |> toCode, 413);
      expect.equal(414 |> ofCode |> toCode, 414);
      expect.equal(415 |> ofCode |> toCode, 415);
      expect.equal(416 |> ofCode |> toCode, 416);
      expect.equal(417 |> ofCode |> toCode, 417);
      expect.equal(418 |> ofCode |> toCode, 418);
      expect.equal(421 |> ofCode |> toCode, 421);
      expect.equal(422 |> ofCode |> toCode, 422);
      expect.equal(423 |> ofCode |> toCode, 423);
      expect.equal(424 |> ofCode |> toCode, 424);
      expect.equal(426 |> ofCode |> toCode, 426);
      expect.equal(428 |> ofCode |> toCode, 428);
      expect.equal(429 |> ofCode |> toCode, 429);
      expect.equal(431 |> ofCode |> toCode, 431);
      expect.equal(451 |> ofCode |> toCode, 451);
    });
  });

  describe("Internal Error", ({test, _}) => {
    test("toCode", ({expect, _}) => {
      expect.equal(toCode(`InternalServerError), 500);
      expect.equal(toCode(`NotImplemented), 501);
      expect.equal(toCode(`BadGateway), 502);
      expect.equal(toCode(`ServiceUnavailable), 503);
      expect.equal(toCode(`GatewayTimeout), 504);
      expect.equal(toCode(`HttpVersionNotSupported), 505);
      expect.equal(toCode(`VariantAlsoNegotiates), 506);
      expect.equal(toCode(`InsufficientStorage), 507);
      expect.equal(toCode(`LoopDetected), 508);
      expect.equal(toCode(`NotExtended), 510);
      expect.equal(toCode(`NetworkAuthenticationRequired), 511);
    });

    test("ofCode", ({expect, _}) => {
      expect.equal(500 |> ofCode |> toCode, 500);
      expect.equal(501 |> ofCode |> toCode, 501);
      expect.equal(502 |> ofCode |> toCode, 502);
      expect.equal(503 |> ofCode |> toCode, 503);
      expect.equal(504 |> ofCode |> toCode, 504);
      expect.equal(505 |> ofCode |> toCode, 505);
      expect.equal(506 |> ofCode |> toCode, 506);
      expect.equal(507 |> ofCode |> toCode, 507);
      expect.equal(508 |> ofCode |> toCode, 508);
      expect.equal(510 |> ofCode |> toCode, 510);
      expect.equal(511 |> ofCode |> toCode, 511);
    });
  });

  describe("Other", ({test, _}) => {
    test("toCode", ({expect, _}) => {
      expect.equal(toCode(`Other(666)), 666)
    });

    test("ofCode", ({expect, _}) =>
      expect.equal(666 |> ofCode |> toCode, 666)
    );
  });
});
