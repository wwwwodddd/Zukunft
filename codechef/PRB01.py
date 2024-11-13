def P(x):
	if x < 2:
		return False
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True

for t in range(int(input())):
	n = int(input())
	print(['no', 'yes'][P(n)])