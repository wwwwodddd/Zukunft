a = range(1, 10)
z = [] + a
for i in range(14):
	b = []
	for j in a:
		for k in range(10):
			if (10 * j + k) % (sum(map(int, list(str(10 * j + k))))) == 0:
				b.append(10 * j + k)
	a = b
	z += a

y = []

def P(x):
	if x < 2:
		return False
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True


for i in z:
	if P(i / sum(map(int, list(str(i))))):
		y.append(i)

ans = 0
for i in y:
	for j in range(10):
		u = 10 * i + j
		if u <= 10 ** 14 and P(u):
			ans += u
print ans