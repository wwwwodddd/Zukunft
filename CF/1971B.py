for t in range(int(input())):
	s = input()
	t = s[1:] + s[0]
	if s == t:
		print('NO')
	else:
		print('YES')
		print(t)
