Fetch_Js.(
  {
    get("https://httpbin.org/get")
    ->Promise.map(
        fun
        | Ok({Response.body, _}) => Js.log2("Body:", Body.toString(body))
        | Error(err) => Js.log2("Error: ", err),
      );
  }
);