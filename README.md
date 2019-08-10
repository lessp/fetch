# Fetch

Fetch aims to provide a common interface for different HTTP and Promise-implementations.

Fetch is loosely based on the Fetch-specification from Whatwg. It has also taken inspiration and attempted to follow community-idioms and best practices with regards to HTTP-requests.

Fetch should be pluggable with any HTTP or Promise-implementation provided it conforms to the common interface.

E.g.

```reason
module Cohttp = {
  module Repromise = Fetch.Make(CohttpRepromise);
};
```

```reason
module H2 = {
  module Lwt = Fetch.Make(H2Lwt);
};
```

```reason
/* or ad hoc */

module Fetch = Fetch.Make({
  type t = Promise.t(result(Response.t, exn));

  let make = (req: Request.t) => /* your custom implementation */

  let fetch = (~body=?, ~headers=[], ~meth=`GET, url) =>
        Request.create(~body, ~headers, ~meth, ~url) |> make;
});
```
