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
      | Ok({Response.body, _}) => Body.toString(body)
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
  post(
    "https://httpbin.org/post",
    ~headers=[
      ("Authorization", "Bearer xyz"),
      ("content-type", "application/json"),
    ],
    ~body=Js.Json.stringify(jsonBody),
  )
  ->Promise.flatMap(
      fun
      | Ok({Response.body, _}) => Body.toString(body)
      | Error(errorMsg) => errorMsg->Promise.resolved,
    )
  ->Promise.map(Js.log)
);