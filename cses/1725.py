def mul(a, b):
	c = [0 for i in range(len(a) + len(b) - 1)]
	for i in range(len(a)):
		for j in range(len(b)):
			c[i + j] += a[i] * b[j]
	return c
f = [1]
c = [0] + [1/6] * 6
n, a, b = map(int, input().split())
for i in range(n):
	f = mul(f, c)
print('%.6f' % sum(f[a:b+1]))
