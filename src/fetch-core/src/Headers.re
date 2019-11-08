type t = (string, string);

let toString = headers => {
  let buffer = Buffer.create(128);

  List.iter(
    ((name, value)) => {
      Buffer.add_string(buffer, name);
      Buffer.add_string(buffer, ": ");
      Buffer.add_string(buffer, value);
      Buffer.add_string(buffer, "\r\n");
    },
    headers,
  );

  Buffer.add_string(buffer, "\r\n");
  Buffer.contents(buffer);
};
