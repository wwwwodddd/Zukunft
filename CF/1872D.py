import math
for t in range(int(input())):
	n, x, y = map(int, input().split())
	c = n // math.lcm(x, y)
	a = n // x - c
	b = n // y - c
	print((n + n - a + 1) * a // 2 - (1 + b) * b // 2)
