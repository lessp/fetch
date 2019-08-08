`Options.t`, `Response.t`, `Fetch.get` etc måste följa interface. Kolla på whatwg fetch?

HTTP-implementation samt response/"promise"-bibliotek exempelvis:

`Lwt.t(Fetch.Response.t)`, `Repromise.t(result(Fetch.Response.t, exn))` är fria för implementation.

```reason
// Kvasi..
module Repromise: Fetch = {
  type response('a) = Repromise.t('a);

  let make = (opts: Options.t) => ....
};

module FetchRepromise = Fetch.make(ToRepromise, H2Request);
```

Ställningstaganden:

- Ramverk implementerar sin egna version av Fetch?
- Community tillhandahåller implementationer för ramverk (t.ex. Httpaf, H2 etc) (tänk DefinitelyTyped)
  - Fördelar, behöver ej mergas eller ramverkets "tillåtelse"

```reason
// Fetch.Revery.Fetch
// Fetch.Revery.Fetch.Repromise
// Fetch.Revery.Fetch.Lwt
Revery.(
  Fetch.get("www.google.com")
  |> mapOk(({Fetch.Response.body, _}) => Printf.printf(body))
);

Fashion.(
  Fetch.post(
    ~headers=[("Content-Type", "application/json")],
    ~body="Hello, World!",
    "www.google.se",
  )
  |> Lwt.map(({Fetch.Response.body, Fetch.Response.status}) =>
       Printf.printf("Body: %s\nStatus: %d", body, status)
     )
);
```
