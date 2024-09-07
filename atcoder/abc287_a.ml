let rec loop n c =
  if n > 0 then begin
    if Scanf.scanf " %s" (=) "For" then loop (n-1) (c+1) else loop (n-1) (c-1)
  end else
    if c < 0 then "No" else "Yes"
  in
  print_endline ((Scanf.scanf "%d" loop) 0)