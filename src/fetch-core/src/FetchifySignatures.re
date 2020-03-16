module type FETCH = {
  type promise('a);

  module Body: {
    type t;

    let empty: unit => t;

    let toString: t => promise(string);
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
  module Status: (module type of Status);
  module Headers: (module type of Headers);
  module Request: (module type of Request);
  module Method: (module type of Method);

  module Body: {
    type t;

    let toString: t => promise(string);
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

  let fetch:
    (
      ~body: string=?,
      ~headers: list(Headers.t)=?,
      ~meth: Method.t=?,
      string
    ) =>
    promise(result(Response.t, string));

  let get:
    (~body: string=?, ~headers: list(Headers.t)=?, string) =>
    promise(result(Response.t, string));
  let post:
    (~body: string=?, ~headers: list(Headers.t)=?, string) =>
    promise(result(Response.t, string));
  let put:
    (~body: string=?, ~headers: list(Headers.t)=?, string) =>
    promise(result(Response.t, string));
  let delete:
    (~body: string=?, ~headers: list(Headers.t)=?, string) =>
    promise(result(Response.t, string));
};
