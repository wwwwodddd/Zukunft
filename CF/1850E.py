import math
for t in range(int(input())):
	n, c = map(int, input().split())
	s = list(map(int, input().split()))
	for i in s:
		c -= i * i
	# 4 * n * w * w + 4 * sum(s) * w - c == 0
	b = 4 * sum(s)
	d = b ** 2 + 16 * n * c
	r = math.isqrt(d)
	print((-b + r) // (8 * n))