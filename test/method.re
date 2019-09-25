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
  };
};

let toStringTest =
  Alcotest.(
    ToString.(
      "Method - toString",
      [test_case("toString", `Quick, toStringTest)],
    )
  );

let () = {
  Alcotest.(run("Method", [toStringTest]));
};