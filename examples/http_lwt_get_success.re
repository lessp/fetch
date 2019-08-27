module Fetch = Fetch_cohttp_lwt;

let statusOk = response => {
  Fetch.Response.(
    switch (response) {
    | Ok(res) when Status.isSuccessful(res.status) => Ok(res)
    | _ => Error(`NoResult)
    }
  );
};

Fetch.(
  fetch("http://httpbin.org/get", ())
  |> Lwt.map(statusOk)
  |> Lwt.map(Console.log)
  |> Lwt_main.run
);