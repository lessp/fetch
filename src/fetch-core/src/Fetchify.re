include FetchifySignatures;

module CreateFetchImplementation = (ProvidedFetch: FETCH) => {
  module Headers = Headers;
  module Status = Status;
  module Method = Method;
  module Request = Request;

  module Body = ProvidedFetch.Body;
  module Response = ProvidedFetch.Response;

  let fetch = ProvidedFetch.fetch;

  let get = fetch(~meth=`GET);
  let post = fetch(~meth=`POST);
  let put = fetch(~meth=`PUT);
  let delete = fetch(~meth=`DELETE);
};
