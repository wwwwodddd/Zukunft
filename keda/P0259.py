def P(n):
	if n < 2:
		return False
	i = 2
	while i * i <= n:
		if n % i == 0:
			return False
		i += 1
	return True
n = int(input())
print(sum(P(i) for i in range(2, n + 1)))
