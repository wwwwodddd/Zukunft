n = int(input())
a = []
i = 2
while i * i <= n:
	while n % i == 0:
		a.append(i)
		n //= i
	i += 1
if n > 1:
	a.append(n)
print(*a)