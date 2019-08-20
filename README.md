# Fetch

A fetch library for ReasonML/OCaml.

**TODO:**

- [ ] Implement a functor for the Response and its functions

## How to use

e.g.

```reason
module Fetch = Fetch_lwt;

Fetch.(
  fetch("http://httpbin.org/get", ())
  |> Lwt.map(
       fun
       | Ok({Response.body, Response.status, _}) =>
         Printf.printf(
           "Status: %d
            Body: %s",
           Response.Status.toCode(status),
           Response.Body.toString(body),
         )
       | Error(_) => Printf.printf("That's an error"),
     )
  |> Lwt_main.run
);
```

## What?

Fetch aims to provide a common interface over different HTTP and Promise-implementations in the ReasonML/OCaml ecosystem.

It is loosely based on the Fetch-specification from [Whatwg](https://fetch.spec.whatwg.org/), and has also taken inspiration and attempted to follow community-idioms and best practices with regards to HTTP-requests.

The goal is to be pluggable with any HTTP or Promise-implementation provided it conforms to the common interface.

E.g.

```reason
module H2 = {
  module Lwt = Fetch.Make(H2Lwt);
};
```

... or ad hoc

```reason
module Fetch = Fetch.Make({
  type t = Promise.t(result(Response.t, exn));

  let make = (req: Request.t) => /* your custom implementation */
});
```

## Why?

There are several different implementations for making HTTP-requests and for handling asynchronous code in the ReasonML/OCaml ecosystem.
This is ultimately a good thing as helps in improving the ecosystem, and also, most times there isn't always a one-size fits all.

The goal is to reduce the burden of transitioning between as well as picking a library to begin with.

By making the implementation-details agnostic and trying to specify a common interface which is also a bit higher-level it hopefully strikes a good balance and can be useful for the community as a whole.
