Fetch.fetch(~meth=`Other("PATCH"), "http://httpbin.org/patch")
|> Lwt.map(res =>
     Printf.printf(
       "Status: %d\nBody: %s",
       res.Fetch.Response.status,
       res.Fetch.Response.body,
     )
   )
|> Lwt_main.run;
