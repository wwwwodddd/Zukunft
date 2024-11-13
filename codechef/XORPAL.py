for t in range(int(input())):
	n = int(input())
	s = input()
	if len(s) % 2 == 0 and s.count('1') % 2 == 1 and s.count('1') != n // 2:
		print('NO')
	else:
		print('YES')