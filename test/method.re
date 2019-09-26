open Fetch_core.Method;

module ToString = {
  let toStringTest = () => {
    open Alcotest;

    check(string, "CONNECT", toString(`CONNECT), "CONNECT");
    check(string, "DELETE", toString(`DELETE), "DELETE");
    check(string, "GET", toString(`GET), "GET");
    check(string, "HEAD", toString(`HEAD), "HEAD");
    check(string, "OPTIONS", toString(`OPTIONS), "OPTIONS");
    check(string, "POST", toString(`POST), "POST");
    check(string, "PUT", toString(`PUT), "PUT");
    check(string, "TRACE", toString(`TRACE), "TRACE");

    check(string, "OTHER", toString(`Other("SOMETHING")), "SOMETHING");
  };
};

module OfString = {
  let ofStringTest = () => {
    open Alcotest;

    check(string, "CONNECT", ofString("CONNECT") |> toString, "CONNECT");
    check(string, "DELETE", ofString("DELETE") |> toString, "DELETE");
    check(string, "GET", ofString("GET") |> toString, "GET");
    check(string, "HEAD", ofString("HEAD") |> toString, "HEAD");
    check(string, "OPTIONS", ofString("OPTIONS") |> toString, "OPTIONS");
    check(string, "POST", ofString("POST") |> toString, "POST");
    check(string, "PUT", ofString("PUT") |> toString, "PUT");
    check(string, "TRACE", ofString("TRACE") |> toString, "TRACE");

    check(string, "OTHER", ofString("SOMETHING") |> toString, "SOMETHING");
  };
};

let toStringTest =
  Alcotest.(
    ToString.(
      "Method - toString",
      [test_case("toString", `Quick, toStringTest)],
    )
  );

let ofStringTest =
  Alcotest.(
    OfString.(
      "Method - ofString",
      [test_case("ofString", `Quick, ofStringTest)],
    )
  );

let () = {
  Alcotest.(run("Method", [toStringTest, ofStringTest]));
};
