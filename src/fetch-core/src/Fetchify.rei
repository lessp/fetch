include (module type of FetchifySignatures);

module CreateFetchImplementation:
  (F: FETCH) => FETCHIFIED with type promise('a) := F.promise('a) and type result('a, 'error) := F.result('a, 'error);
