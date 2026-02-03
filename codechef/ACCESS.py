for t in range(int(input())):
	n, x = map(int, input().split())
	s = input().split('1')
	if len(s[0]) > 0 or max(map(len, s)) > x:
		print('NO')
	else:
		print('YES')
