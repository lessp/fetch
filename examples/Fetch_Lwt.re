module LetOperators = {
  let (let.flatMapOk) = (promise, fn) =>
    Lwt.bind(
      promise,
      fun
      | Ok(response) => fn(response)
      | Error(e) => Lwt.return(Error(e)),
    );

  let (let.flatMap) = (promise, fn) => Lwt.bind(promise, fn);
};

open LetOperators;

let result =
  Fetch.(
    {
      let.flatMapOk {Response.body, _} = get("https://httpbin.org/get");
      let.flatMap bodyString = Body.toString(body);

      Lwt.return(Ok(bodyString));
    }
  )
  |> Lwt_main.run;

switch (result) {
| Ok(body) => Console.log("Body: " ++ body)
| Error(e) => Console.log("That's an error: " ++ e)
};
