open LetOperators;

Fetch_Js.(
  {
    let.flatMapOk {Response.body, _} = get("https://httpbin.org/get");

    Js.log(Body.toString(body));

    Promise.resolved(Ok());
  }
);
