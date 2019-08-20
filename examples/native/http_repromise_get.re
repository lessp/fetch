module F = Fetch.Cohttp.Repromise;

F.fetch("http://httpbin.org/get", ())
|> Repromise.wait(
     fun
     | Ok({Fetch.Response.body, Fetch.Response.status, _}) =>
       Console.log((
         "Status-Code",
         status |> Fetch.Response.Status.toCode,
         "Body",
         body |> Fetch.Response.Body.toString,
       ))
     | Error(_) => Console.log("That's an error"),
   )
|> Repromise_lwt.run;
