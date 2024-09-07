t = int(input())
for i in range(t):
	n = int(input())
	i = 2
	a = []
	while i * i <= n:
		while n % i == 0:
			a.append(i)
			n //= i
		i += 1
	if n > 1:
		a.append(n)
	print(*a)