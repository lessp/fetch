let handleResponse =
  Fetch.Response.(
    fun
    | Ok({status, _}) when Status.isSuccessful(status) => "Success!"
    | _ => "That's anything but successful. :-("
  );

let fetchWithAuth = Fetch.fetch(~headers=[("Authorisation", "Bearer xyz")]);
let fetchWithAuthAndBody = fetchWithAuth(~body="Hello World!");

fetchWithAuthAndBody("https://httpbin.org/get")
|> Lwt.map(handleResponse)
|> Lwt.map(Console.log)
|> Lwt_main.run;
