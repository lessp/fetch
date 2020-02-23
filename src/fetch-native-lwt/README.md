# fetch-native-lwt

Fetch client for native ReasonML.

## Getting started

1. Install

Currently to install, you'll need `esy` and pin `fetch-native-lwt` to point to this Github-repo.

```json
"dependencies": {
  "fetch-native-lwt": "github:lessp/reason-fetch:fetch-native-lwt.json#<commit-hash>"
}
```

Depending on your platform, you may need to pin the following resolution as well:

```json
"resolutions": {
  "@opam/conf-libssl": "esy-packages/esy-openssl#648930fa614886bc189f9b5c31f64f0b663fceee"
}
```

2. Add Fetch to your dune libraries:

```lisp
(libraries ... fetch-native-lwt)
```

3. Make your first request:

```re
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
       | Error(e) => Printf.printf("That's an error: %s", e),
     )
  |> Lwt_main.run
);
```
