import math
def K(x):
	for i in range(2, x):
		if x % i:
			return i
m = 50
f = [0 for i in range(m + 1)]
f[2] = 1
for i in range(3, m + 1):
	f[i] = f[K(i)] + 1
def F(x):
	d = 1
	z = x
	for i in range(1, m):
		d = math.lcm(d, i)
		z += x // d * (f[i + 1] - f[i])
	return z
l, r = map(int, input().split())
print(F(r) - F(l - 1))
