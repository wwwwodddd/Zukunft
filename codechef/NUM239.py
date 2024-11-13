def F(n):
	m = n // 10
	c = m * 3
	for i in [2, 3, 9]:
		if m * 10 + i <= n:
			c += 1
	return c
for t in range(int(input())):
	x, y = map(int, input().split())
	print(F(y) - F(x - 1))