Fetch.(
  fetch("https://httpbin.org/get", ())
  |> Lwt.map(
       fun
       | Ok({Response.body, status, url, _}) => {
           Printf.printf(
             "Status-Code: %d\nBody: %s\nUrl: %s",
             Response.Status.to_code(status),
             Response.Body.to_string(body),
             url,
           );
         }
       | Error(_) => Printf.printf("That's an error"),
     )
  |> Lwt_main.run
);
