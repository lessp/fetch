module R_lwt = Repromise_lwt;
module Refetch = Fetch.Repromise;

let mapOk = (action, promise) =>
  promise
  |> Repromise.map(
       fun
       | Ok(v) => action(v)
       | Error(e) => Error(e),
     );

let tap = (action, promise) =>
  promise
  |> Repromise.map(value => {
       action(value);

       value;
     });

let mapError = (action, promise) =>
  promise
  |> Repromise.map(
       fun
       | Ok(v) => Ok(v)
       | Error(e) => Error(action(e)),
     );

Refetch.get("https://cat-fact.herokuapp.com/facts/random")
|> mapOk(({Fetch.Response.body, _}) => Ok(body))
|> tap(Console.log)
|> Repromise.wait(
     fun
     | Ok(_s) => Console.log("Ok, done.")
     | Error(e) => Console.log(("Error", e)),
   )
|> R_lwt.run;
