n = 123456787654321
z = 0

f = []
while n > 0:
	f.append((n + 1) / 2)
	n /= 2

m = len(f)
for i in range(m):
	for j in range(m):
		for k in range(m):
			if i ^ j ^ k != 0:
				z += f[i] * f[j] * f[k]
print z % 1234567890