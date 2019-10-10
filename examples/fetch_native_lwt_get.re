Fetch.(
  fetch("https://httpbin.org/get")
  |> Lwt.map(
       fun
       | Ok({Fetch.Response.body, status, url, _}) => {
           Printf.printf(
             "Status-Code: %d\nBody: %s\nUrl: %s",
             Fetch.Response.Status.toCode(status),
             Fetch.Response.Body.toString(body),
             url,
           );
         }
       | Error(_) => Printf.printf("That's an error"),
     )
  |> Lwt_main.run
);
