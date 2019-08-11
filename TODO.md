**Thoughts and improvements**

It'd be nice for convenience to make `Fetch.Response.Status` and `Body` available under `Fetch.Body` and status respectively.

---

The only real thing that you should be switchable is the main `Fetch.make`-function and I guess that main-type as well. Currently it's a bit unfortunate that you have to also implement the fetch-calls, especially if we'd decide on providing convenience-function for the standard HTTP-methods e.g. `Fetch.get/put/patch/delete/etc`.

In other words, ultimately it'd be nice if we could turn

```reason
  module Implementation: {
    type t = Implementation.t(result(Response.t, exn));
    let make: Request.t => t;
    let fetch:
      (
        ~body: string=?,
        ~headers: list(Headers.t)=?,
        ~meth: Method.t=?,
        string
      ) =>
      t;
  };
```

to this:

```reason
  module Implementation: {
    type t = Implementation.t(result(Response.t, exn));
    let make: Request.t => t;
  };
```

---

With the current structure there's also a clash with namespaces e.g.

```reason
module F = Fetch.Cohttp.Lwt;

F.fetch("http://httpbin.org/get")
|> Lwt.map(
     fun
     | Ok({Fetch.Response.body, Fetch.Response.status, _}) =>
```

it'd be nice if we could do:

```reason
module F = Fetch.Cohttp.Lwt;

F.fetch("http://httpbin.org/get")
|> Lwt.map(
     fun
     | Ok({F.Response.body, F.Response.status, _}) =>
```
