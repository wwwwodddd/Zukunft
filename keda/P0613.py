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
n = int(input())
for i in range(2, n):
	if P(i) and P(n - i):
		z = max(z, i * (n - i))
print(z)
