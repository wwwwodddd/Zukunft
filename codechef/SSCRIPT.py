for t in range(int(input())):
	n, k = map(int, input().split())
	s = input()
	z = c = 0
	for i in s:
		if i == '*':
			c += 1
		else:
			c = 0
		z = max(z, c)
	print(['NO', 'YES'][z >= k])