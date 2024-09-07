def P(n):
	if n < 2:
		return 0
	i = 2
	while i * i <= n:
		if n % i == 0:
			return 0
		i += 1
	return 1

for t in range(int(input())):
	n = int(input())
	print(P(n))