module Fetch = Fetch_native_lwt;

let handleResponse =
  Fetch.Response.(
    fun
    | Ok({status, _}) when Status.isSuccessful(status) => "Success!"
    | _ => "That's anything but successful. :-("
  );

Fetch.(
  fetch("http://httpbin.org/get", ())
  |> Lwt.map(handleResponse)
  |> Lwt.map(Console.log)
  |> Lwt_main.run
);
