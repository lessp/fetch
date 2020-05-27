open LetOperators;

let jsonBody = Js.Json.parseExn({|
{
  "foo": "bar"
}
|});

Fetch_Js.(
  {
    let.flatMapOk {Response.body, _} =
      post(
        "https://httpbin.org/post",
        ~headers=[
          ("Authorization", "Bearer xyz"),
          ("content-type", "application/json"),
        ],
        ~body=Js.Json.stringify(jsonBody),
      );

    Js.log2("Parse JSON: ", Body.toString(body)->Js.Json.parseExn);

    Promise.resolved(Ok());
  }
);
