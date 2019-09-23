module Fetch = Fetch_cohttp_lwt;

Fetch.(
  fetch("http://httpbin.org/get", ())
  |> Lwt.map(
       fun
       | Ok({Response.body, Response.status, _}) =>
         Printf.printf(
           "Status-Code: %d\nBody: %s",
           Response.Status.toCode(status),
           Response.Body.toString(body),
         )
       | Error(_) => Printf.printf("That's an error"),
     )
  |> Lwt_main.run
);
