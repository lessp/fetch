let (let.flatMapOk) = (promise, fn) =>
  Promise.flatMap(
    promise,
    fun
    | Ok(response) => fn(response)
    | Error(e) => Promise.resolved(Belt.Result.Error(e)),
  );

let (let.flatMap) = (promise, fn) => Promise.flatMap(promise, fn);
let (let.map) = Promise.map;
let (let.mapOk) = Promise.mapOk;
