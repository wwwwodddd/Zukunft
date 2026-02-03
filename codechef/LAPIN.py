for t in range(int(input())):
	s = input()
	if sorted(s[:len(s) // 2]) == sorted(s[-(len(s) // 2):]):
		print('YES')
	else:
		print('NO')