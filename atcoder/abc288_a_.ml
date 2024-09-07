let loop n =
  for _ = 1 to n do
    Printf.printf "%d\n" (Scanf.scanf(" %d %d") (+));
  done in
  Scanf.scanf "%d" loop