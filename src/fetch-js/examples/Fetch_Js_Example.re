module LetOperators = {
  let (let.flatMapOk) = (promise, fn) =>
    Promise.flatMap(
      promise,
      fun
      | Ok(response) => fn(response)
      | Error(e) => Promise.resolved(Belt.Result.Error(e)),
    );

  let (let.flatMap) = (promise, fn) => Promise.flatMap(promise, fn);
};

open LetOperators;

Fetch_Js.(
  {
    let.flatMapOk {Response.body, _} = get("https://httpbin.org/get");
    Js.log(Body.toString(body));

    Promise.resolved(Ok());
  }
);

Fetch_Js.(
  get("https://httpbin.org/get")
  ->Promise.map(
      fun
      | Ok({Response.status, _}) when Fetch_Js.Status.isSuccessful(status) => "Success!"
      | _ => "That's anything but successful. :-(",
    )
  ->Promise.get(Js.log)
);

Fetch_Js.(
  post(
    "https://httpbin.org/post",
    ~headers=[("Authorization", "Bearer xyz")],
    ~body="Hello, World!",
  )
  ->Promise.flatMap(
      fun
      | Ok({Response.body, _}) => Body.toString(body)->Promise.resolved
      | Error(errorMsg) => errorMsg->Promise.resolved,
    )
  ->Promise.map(Js.log)
);

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