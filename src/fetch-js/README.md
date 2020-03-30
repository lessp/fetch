# Fetch JS

Fetch client for BuckleScript.

## Examples

```reason
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
```

See [the examples](./examples/).
