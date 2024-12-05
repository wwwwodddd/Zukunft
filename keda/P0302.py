def P(n):
	if n < 2:
		return False
	i = 2
	while i * i <= n:
		if n % i == 0:
			return False
		i += 1
	return True
l, r = map(int, input().split())
print(sum(P(i) for i in range(l, r + 1)))
