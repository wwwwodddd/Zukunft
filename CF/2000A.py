for t in range(int(input())):
	s = input()
	if len(s) > 2 and s[:2] == '10' and s[2] != '0' and int(s[2:]) > 1:
		print('YES')
	else:
		print('NO')