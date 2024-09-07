def P(n):
	if n < 2:
		return 0
	i = 2
	while i * i <= n:
		if n % i == 0:
			return 0
		i += 1
	return 1

n = int(input())
a = []
i = 2
while len(a) < n:
	if P(i):
		a.append(i)
	i += 1
for i in a:
	print(i)