[%bs.raw {| require("isomorphic-fetch") |}];

module FetchImplementation = {
  module Headers = Fetch_Core.Headers;
  module Method = Fetch_Core.Method;
  module Status = Fetch_Core.Status;

  type promise('a) = Promise.t('a);
  type result('a, 'error) = Belt.Result.t('a, 'error);

  module Body = {
    type t = Js.Promise.t(string);

    let make = response => {
      let body = BsFetch.Bs_Fetch.Response.text(response);
      body;
    };

    let toString = body => {
      let (promise, resolve) = Promise.pending();

      body
      |> Js.Promise.then_(body => {
           resolve(body);
           Js.Promise.resolve();
         })
      |> ignore;

      promise;
    };

    let ofString = body => Js.Promise.resolve(body);
  };

  module Response = {
    module Body = Body;
    module Status = Status;

    type t = {
      body: Body.t,
      headers: list(Headers.t),
      status: Status.t,
      url: string,
    };

    let make = (~body, ~headers, ~status, ~url) => {
      body,
      headers,
      status,
      url,
    };
  };

  let fetch = (~body=?, ~headers=[], ~meth=`GET, url) => {
    let {Fetch_Core.Request.headers, body, meth, url} =
      Fetch_Core.Request.create(~body, ~headers, ~meth, ~url);

    let (promise, resolve) = Promise.pending();

    let decodeRequestMethod = meth => {
      let methStringified = Method.toString(meth);

      switch (methStringified) {
      | "GET" => BsFetch.Bs_Fetch.Get
      | "HEAD" => Head
      | "POST" => Post
      | "PUT" => Put
      | "DELETE" => Delete
      | "CONNECT" => Connect
      | "OPTIONS" => Options
      | "TRACE" => Trace
      | "PATCH" => Patch
      | otherMethod => Other(otherMethod)
      };
    };

    BsFetch.Bs_Fetch.fetchWithInit(
      url,
      BsFetch.Bs_Fetch.RequestInit.make(
        ~method_=decodeRequestMethod(meth),
        ~body=
          BsFetch.Bs_Fetch.BodyInit.make(
            Belt.Option.getWithDefault(body, ""),
          ),
        ~headers=
          BsFetch.Bs_Fetch.HeadersInit.makeWithDict(
            Js.Dict.fromList(headers),
          ),
        (),
      ),
    )
    |> Js.Promise.then_(response => {
         resolve(
           Ok(
             Response.make(
               ~status=
                 Status.make(BsFetch.Bs_Fetch.Response.status(response)),
               ~body=Body.make(response),
               ~headers,
               ~url,
             ),
           ),
         );
         Js.Promise.resolve();
       })
    |> Js.Promise.catch(error =>
         Js.Promise.resolve(resolve(Error(Js.String.make(error))))
       )
    |> ignore;

    promise;
  };
};

include Fetch_Core.Fetchify.CreateFetchImplementation(FetchImplementation);