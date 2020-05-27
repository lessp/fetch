include
  Fetch_Core.Fetchify.FETCHIFIED with
    type promise('a) := Promise.t('a) and
    type result('a, 'error) := Belt.Result.t('a, 'error);
