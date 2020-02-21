Fetch.(
  get("https://httpbin.org/get")
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
       | Error(error) => print_string(error),
     )
  |> Lwt_main.run
);
