n, m = map(int, input().split())
if m % n != 0:
	print(-1)
else:
	r = m // n
	c = 0
	while r % 2 == 0:
		r //= 2
		c += 1
	while r % 3 == 0:
		r //= 3
		c += 1
	if r == 1:
		print(c)
	else:
		print(-1)