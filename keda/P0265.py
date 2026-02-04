def P(n):
	if n < 2:
		return False
	i = 2
	while i * i <= n:
		if n % i == 0:
			return False
		i += 1
	return True
z = 0
for i in range(6, 101, 2):
	for j in range(2, i):
		if P(j) and P(i - j):
			print('%d=%d+%d' % (i, j, i - j))
			break