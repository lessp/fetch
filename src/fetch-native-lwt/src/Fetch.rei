include
  Fetch_Core.Fetchify.FETCHIFIED with
    type promise('a) := Lwt.t('a) and
    type result('a, 'error) := Result.t('a, 'error);
