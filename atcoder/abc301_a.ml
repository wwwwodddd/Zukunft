let zuo n s = if ((Core.String.count (String.sub s 0 (n-1+n mod 2)) ~f:((=)'T')) < (n+1)/2) then 'A' else 'T' in print_char((Scanf.scanf "%d %s" zuo))
