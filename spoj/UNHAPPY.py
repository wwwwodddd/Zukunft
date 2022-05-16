f = [[0 for j in range(2000)]for i in range(20)]
f[0][0] = 1
for i in range(19):
	for j in range(2000):
		if f[i][j]:
			for k in range(10):
				f[i + 1][j + k * k] += f[i][j]

def S(n):
	return sum(int(i)**2 for i in str(n))

a = set()
for i in range(2000):
	t = i
	for j in range(10):
		if t == 1:
			a.add(i)
			break
		t = S(t)

def F(n):
	s = str(n)[::-1]
	t = 0
	z = n
	for i in range(len(s))[::-1]:
		for j in range(int(s[i])):
			for b in a:
				if b >= t + j ** 2:
					z -= f[i][b - t - j ** 2]
		t += int(s[i]) ** 2
	return z

while True:
	x, y = map(int, input().split())
	if y == 0:
		break
	print(F(y + 1) - F(x))