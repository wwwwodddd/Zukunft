def P(x):
	if x < 2:
		return False
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
			break
		i += 1
	else:
		return True
n = int(input())
print(['no', 'yes'][P(n)])
