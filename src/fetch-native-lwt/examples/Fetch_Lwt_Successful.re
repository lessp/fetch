let handleResponse =
  Fetch.(
    fun
    | Ok({Response.status, _}) when Status.isSuccessful(status) => "Success!"
    | _ => "That's anything but successful. :-("
  );

let fetchWithAuth = Fetch.get(~headers=[("Authorisation", "Bearer xyz")]);
let fetchWithAuthAndBody = fetchWithAuth(~body="Hello World!");

fetchWithAuthAndBody("https://httpbin.org/get")
|> Lwt.map(handleResponse)
|> Lwt.map(Console.log)
|> Lwt_main.run;
