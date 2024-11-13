for t in range(int(input())):
	n = int(input())
	s = input()
	if s[-1] in s[:-1]:
		print('YES')
	else:
		print('NO')
