module F = Fetch.Cohttp.Lwt;

F.fetch("http://httpbin.org/get")
|> Lwt.map(
     fun
     | Ok({Fetch.Response.body, Fetch.Response.status, _}) =>
       Printf.printf(
         "Status-Code: %d\nBody: %s",
         status |> Fetch.Response.Status.toCode,
         body |> Fetch.Response.Body.toString,
       )
     | Error(_) => Printf.printf("That's an error"),
   )
|> Lwt_main.run;
