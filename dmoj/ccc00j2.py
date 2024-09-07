def F(n):
	a = []
	m = n
	while n > 0:
		d = n % 10
		if d in [0, 1, 8]:
			a.append(d)
		elif d in [6, 9]:
			a.append(15 - d)
		else:
			return False
		n //= 10
	return int(''.join(map(str, a))) == m
m = int(input())
n = int(input())
z = 0
for i in range(m, n + 1):
	if F(i):
		z += 1
print(z)