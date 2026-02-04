def P(n):
	if n < 2:
		return False
	i = 2
	while i * i <= n:
		if n % i == 0:
			return False
		i += 1
	return True
for i in range(100, 1000):
	if P(i) and str(i) == str(i)[::-1]:
		print(i)
