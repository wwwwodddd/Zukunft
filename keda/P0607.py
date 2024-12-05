def P(n):
	i = 2
	while i * i <= n:
		while n % i == 0:
			n //= i
		if n == 1:
			return i
		i += 1
	return n

n, m = map(int, input().split())
a = [P(i) for i in range(n, m + 1)]
print(','.join(map(str, a)))