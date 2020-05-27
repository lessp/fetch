Fetch_Js.(
  get("https://httpbin.org/get")
  ->Promise.map(
      fun
      | Ok({Response.status, _}) when Status.isSuccessful(status) => "Success!"
      | _ => "That's anything but successful. :-(",
    )
  ->Promise.get(Js.log)
);
