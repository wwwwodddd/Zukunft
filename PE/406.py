def C(n, m):
	r = 1
	for i in range(m):
		r = r * (n - i) / (i + 1)
	return r
def W(v, a, b, n):
	re = 0
	for i in range(int(v / a) + 1):
		for j in range(int((v - i * a) / b) + 1):
			if i * a + j * b > v:
				continue
			re += C(i + j, j)
			if re >= n:
				return True
	return re >= n
def S(n, a, b):
	L = 0.0
	R = 1.0
	while not W(R, a, b, n):
		R *= 2
	for _ in range(120):
		M = (L + R) / 2
		if W(M, a, b, n):
			R = M
		else:
			L = M
	return (L + R) / 2
f = [0, 1]
for i in range(31):
	f.append(f[-1] + f[-2])


ans = 0.0
for i in range(1, 31):
	tmp = S(10 ** 12, i ** 0.5, f[i] ** 0.5)
	print tmp
	ans += tmp
print '%.12f' % ans
