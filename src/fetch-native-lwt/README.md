# fetch-native-lwt

Fetch client for native ReasonML.

## Getting started

1. Install

Currently to install, you'll need `esy` and pin `fetch-native-lwt` to point to this github-repo.

```json
"dependencies": {
  ...
  "fetch-native-lwt": "github:lessp/reason-fetch:fetch-native-lwt.json#<commit-hash>"
}
```

2. Add Fetch to your dune libraries:

```lisp
(libraries ... fetch-native-lwt)
```

3. Make your first request:

```re
Fetch.(
  fetch("https://httpbin.org/get", ())
  |> Lwt.map(
       fun
       | Ok({Response.body, status, url, _}) => {
           Printf.printf(
             "Status-Code: %d\nBody: %s\nUrl: %s",
             Response.Status.toCode(status),
             Response.Body.toString(body),
             url,
           );
         }
       | Error(_) => Printf.printf("That's an error"),
     )
  |> Lwt_main.run
);
```
