Fetch.(
  fetch("https://httpbin.org/get")
  |> Lwt.map(
       fun
       | Ok({Response.body, status, url, headers}) => {
           Printf.printf(
             "Headers: \n%sStatus-Code: %d\nBody: %s\nUrl: %s",
             Response.Headers.toString(headers),
             Response.Status.toCode(status),
             Response.Body.toString(body),
             url,
           );
         }
       | Error(_) => Printf.printf("That's an error"),
     )
  |> Lwt_main.run
);
