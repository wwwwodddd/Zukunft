awk '{ for (i=1;i<=NF;i++) s[i] = s[i]" "$i; } END { for (i=1;i<=NF;i++) print s[i] }' file.txt | sed 's/^ //g'