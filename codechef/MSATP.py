for t in range(int(input())):
	n = int(input())
	s = input()
	t = input()
	c = [0, 0, 0]
	for i in range(n):
		c[int(s[i]) + int(t[i])] += 1
	if c[0] % 2 + c[1] % 2 + c[2] % 2 < 2:
		print('YES')
	else:
		print('NO')