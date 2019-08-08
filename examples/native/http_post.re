Fetch.Repromise.post(
  "http://httpbin.org/post",
  ~body="Hello, World!",
  ~headers=[("Content-Type", "text/plain")],
)
|> Repromise.wait(
     Fetch.Response.(
       fun
       | Ok({status, body}) => Console.log(("Status", status, "Body", body))
       | Error(e) => Console.log(e)
     ),
   )
|> Repromise_lwt.run;
