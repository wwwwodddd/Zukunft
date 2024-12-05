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
z = 0
for i in range(2, n + 1):
	if P(i - 2) and P(i):
		print(i - 2, i)
		z += 1
if z == 0:
	print('empty')
