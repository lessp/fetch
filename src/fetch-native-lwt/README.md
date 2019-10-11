# fetch-native-lwt

Fetch client for native ReasonML.

## Getting started

1. Install

Currently to install, you'll need `esy` and pin `fetch-native-lwt` to point to this Github-repo.

```json
"dependencies": {
  "fetch-native-lwt": "github:lessp/reason-fetch:fetch-native-lwt.json#<commit-hash>"
},
"resolutions": {
  "@opam/httpaf-lwt-unix": "anmonteiro/httpaf:httpaf-lwt-unix.opam#76b461bed081c64908fb1fdfa076ab2c936ca622",
  "@opam/httpaf-lwt": "anmonteiro/httpaf:httpaf-lwt.opam#76b461bed081c64908fb1fdfa076ab2c936ca622",
  "@opam/httpaf": "anmonteiro/httpaf:httpaf.opam#76b461bed081c64908fb1fdfa076ab2c936ca622"
}
```

2. Add Fetch to your dune libraries:

```lisp
(libraries ... fetch-native-lwt)
```

3. Make your first request:

```re
Fetch.(
  fetch("https://httpbin.org/get")
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
