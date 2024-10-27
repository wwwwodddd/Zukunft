for t in range(int(input())):
	n = input()
	s = sum(map(int, input().split()))
	r = int(s ** 0.5 + 0.5)
	if r * r == s:
		print('YES')
	else:
		print('NO')