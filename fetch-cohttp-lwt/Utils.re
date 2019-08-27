module Option = {
  let map = mapper =>
    fun
    | None => None
    | Some(x) => Some(mapper(x));

  let withDefault = default =>
    fun
    | None => default
    | Some(x) => x;
};