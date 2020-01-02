open TestFramework;
open Fetch_Core.Method;

describe("Method", ({test, _}) => {
  test("toString", ({expect, _}) => {
    expect.equal("CONNECT", toString(`CONNECT));
    expect.equal("DELETE", toString(`DELETE));
    expect.equal("GET", toString(`GET));
    expect.equal("HEAD", toString(`HEAD));
    expect.equal("OPTIONS", toString(`OPTIONS));
    expect.equal("POST", toString(`POST));
    expect.equal("PUT", toString(`PUT));
    expect.equal("TRACE", toString(`TRACE));

    expect.equal("SOMETHING", toString(`Other("SOMETHING")));
  });

  test("ofString", ({expect, _}) => {
    expect.equal(ofString("CONNECT") |> toString, "CONNECT");
    expect.equal(ofString("DELETE") |> toString, "DELETE");
    expect.equal(ofString("GET") |> toString, "GET");
    expect.equal(ofString("HEAD") |> toString, "HEAD");
    expect.equal(ofString("OPTIONS") |> toString, "OPTIONS");
    expect.equal(ofString("POST") |> toString, "POST");
    expect.equal(ofString("PUT") |> toString, "PUT");
    expect.equal(ofString("TRACE") |> toString, "TRACE");

    expect.equal(ofString("SOMETHING") |> toString, "SOMETHING");
  });
});
