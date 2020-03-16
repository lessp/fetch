include (module type of FetchifySignatures);

module CreateFetchImplementation:
  (F: FETCH) => FETCHIFIED with type promise('a) := F.promise('a);
