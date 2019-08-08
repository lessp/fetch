Fetch.Repromise.put("http://httpbin.org/put", ~body="Hello, World!")
|> Repromise.wait(
     Fetch.Response.(
       fun
       | Ok({status, body}) => Console.log(("Status", status, "Body", body))
       | Error(e) => Console.log(e)
     ),
   )
|> Repromise_lwt.run;
