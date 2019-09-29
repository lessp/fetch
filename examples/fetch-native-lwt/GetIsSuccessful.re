let map_successful =
  Fetch.Response.(
    fun
    | Ok({status, _}) when Status.is_successful(status) => "Success!"
    | _ => "That's anything but successful. :-("
  );

Fetch.(
  fetch("http://httpbin.org/get", ())
  |> Lwt.map(map_successful)
  |> Lwt.map(Console.log)
  |> Lwt_main.run
);
