# Fetch

A fetch interface/functor for ReasonML/OCaml.

# Table of Contents

- [What](#what)
- [Why](#why)

## What?

Fetch aims to provide a common interface over different HTTP and Promise-implementations in the ReasonML/OCaml ecosystem.

It is based on the Fetch-specification from [Whatwg](https://fetch.spec.whatwg.org/), but makes conscious trade-offs. It has also taken inspiration and attempted to follow community-idioms and best practices with regards to HTTP-requests.

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

## Why?

There are several different implementations for making HTTP-requests and for handling asynchronous code in the ReasonML/OCaml ecosystem.
This is ultimately a good thing as helps in improving the ecosystem, and also, most times there isn't always a one-size fits all.

The goal is to reduce the burden of transitioning between as well as picking a library to begin with.

By making the implementation-details agnostic and trying to specify a common interface which is also a bit higher-level it hopefully strikes a good balance and can be useful for the community as a whole.
