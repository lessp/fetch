let printResponse = ({status, body}: Fetch.Response.t) =>
  Printf.printf("Status-Code: %d\nBody: %s", status, body);

Fetch.delete("http://httpbin.org/delete")
|> Lwt.map(printResponse)
|> Lwt_main.run;
