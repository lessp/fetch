module type FETCH = {
  type promise('a);
  type result('a, 'error);

  module Body: {
    type t;

    let toString: t => string;
    let ofString: string => t;
  };

  module Response: {
    module Body = Body;
    module Status = Status;

    type t = {
      body: Body.t,
      headers: list(Headers.t),
      status: Status.t,
      url: string,
    };
  };

  let fetch:
    (
      ~body: string=?,
      ~headers: list(Headers.t)=?,
      ~meth: Method.t=?,
      string
    ) =>
    promise(result(Response.t, string));
};

module type FETCHIFIED = {
  type promise('a);
  type result('a, 'error);

  module Status: (module type of Status);
  module Headers: (module type of Headers);
  module Request: (module type of Request);
  module Method: (module type of Method);

  module Body: {
    type t;

    /** Takes a Body.t and returns a string.

        {2 Examples}
        {[Fetch.Body.toString(body) == string]}
    */
    let toString: t => string;

    /** Takes a string and returns Body.t.

        {2 Examples}
        {[Fetch.Body.ofString("Some, body") == Body.t]}
    */
    let ofString: string => t;
  };

  module Response: {
    type t = {
      body: Body.t,
      headers: list(Headers.t),
      status: Status.t,
      url: string,
    };
  };

  /** Make a fetch-request with a [body] (optional), [headers] (optional), [method] (defaults to
   * `GET) to endpoint [url].

      {2 Examples}
      {[Fetch.fetch("https://example.com")]}
      {[
        Fetch.fetch(
          "https://example.com",
          ~body="Some, body",
          ~headers=[("Authorization", "Bearer xyz")],
          ~meth=`POST)
      ]}
  */
  let fetch:
    (
      ~body: string=?,
      ~headers: list(Headers.t)=?,
      ~meth: Method.t=?,
      string
    ) =>
    promise(result(Response.t, string));

  /** Make a GET-request with a [body] (optional), [headers] (optional) to endpoint [url].

      {2 Examples}
      {[Fetch.get("https://example.com")]}
      {[
        Fetch.get(
          "https://example.com",
          ~headers=[("Authorization", "Bearer xyz")],
        )
      ]}
  */
  let get:
    (~body: string=?, ~headers: list(Headers.t)=?, string) =>
    promise(result(Response.t, string));

  /** Make a POST-request with a [body] (optional), [headers] (optional) to endpoint [url].

      {2 Examples}
      {[
        Fetch.post(
          "https://example.com",
          ~body="Some, body",
          ~headers=[("Authorization", "Bearer xyz")],
        )
      ]}
  */
  let post:
    (~body: string=?, ~headers: list(Headers.t)=?, string) =>
    promise(result(Response.t, string));

  /** Make a PUT-request with a [body] (optional), [headers] (optional) to endpoint [url].

      {2 Examples}
      {[
        Fetch.put(
          "https://example.com/movies/1",
          ~body="Some, body",
          ~headers=[("Authorization", "Bearer xyz")],
        )
      ]}
  */
  let put:
    (~body: string=?, ~headers: list(Headers.t)=?, string) =>
    promise(result(Response.t, string));

  /** Make a DELETE-request with a [body] (optional), [headers] (optional) to endpoint [url].

      {2 Examples}
      {[
        Fetch.delete(
          "https://example.com/movies/1",
          ~headers=[("Authorization", "Bearer xyz")],
        )
      ]}
  */
  let delete:
    (~body: string=?, ~headers: list(Headers.t)=?, string) =>
    promise(result(Response.t, string));
};
