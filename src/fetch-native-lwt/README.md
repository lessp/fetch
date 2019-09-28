# fetch-native-lwt

Fetch client for native ReasonML.

## Getting started

1. Install

```sh
esy add fetch-native-lwt
```

2. Add Fetch to your dune libraries:

```lisp
(libraries ... fetch-native-lwt)
```

3. Make your first request:

```re
open Fetch_native_lwt;

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
|> Lwt_main.run;
```
