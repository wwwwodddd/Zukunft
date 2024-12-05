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
print(sum(i for i in map(int, input().split()) if P(i)))
