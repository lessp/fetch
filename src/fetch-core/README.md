# Fetch

[![npm version](https://badge.fury.io/js/fetch-core.svg)](https://badge.fury.io/js/fetch-core)

A fetch interface/functor for ReasonML/OCaml.

## Description

A fetch interface and implementation based on the Fetch-specification from [Whatwg](https://fetch.spec.whatwg.org/). That said, it makes conscious trade-offs and decisions to fit the Reason/OCaml-ecosystem. It also takes inspiration and attempts to follow community-idioms and best practices with regards to HTTP-clients.

The goal is to be pluggable with any HTTP or Promise-implementation provided it conforms to the common interface.

E.g.

```re
module Fetch = Fetch_Core.Fetchify.Make({
  module Response = {
    /* your implementation */
  };

  type t = Promise.t(result(Response.t, exn));

  let make = (req: Request.t) => /* your custom implementation */
});
```
