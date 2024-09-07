let rec loop n =
  if n > 0 then begin
    Printf.printf "%d\n" (Scanf.scanf(" %d %d") (+));
    loop (n - 1)
  end else
    0
  in
  Scanf.scanf "%d" loop