n = 70
l = 10 ** 20
h = 10 ** 60
c = [0 for i in range(n + 1)]
for i in range(1, n + 1):
	j = 2
	while j <= i:
		while i % j == 0:
			c[j] += 1
			i //= j
		j += 1


a = [(1, 1)]
b = [(1, 1)]

for i in range(1, n + 1):
	if c[i] != 0:
		print(i, c[i])
		if i < 12:
			f = []
			for x, y in a:
				for k in range(c[i] + 1):
					f.append((x * i ** k, y * (-i) ** k))
			a = f
		else:
			f = []
			for x, y in b:
				for k in range(c[i] + 1):
					f.append((x * i ** k, y * (-i) ** k))
			b = f

a = sorted(a)
b = sorted(b)
print(len(a), len(b))

def S(h):
	s = 0
	for x, y in b:
		s += y
	z = 0
	j = len(b) - 1
	for i in range(len(a)):
		while j >= 0 and a[i][0] * b[j][0] > h:
			s -= b[j][1]
			j -= 1
		z = (z + a[i][1] * s) % 1000000007
	return z
print(S(h) - S(l - 1))