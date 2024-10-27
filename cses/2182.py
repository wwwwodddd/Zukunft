mod = 1000000007
n = int(input())
a = []
p = [1 for i in range(n + 1)]
z0 = 1
z1 = 1
z2 = 1
for i in range(n):
	x, y = map(int, input().split())
	a.append((x, y))
	z0 = z0 * (y + 1) % mod
	z1 = z1 * (pow(x, y + 1, mod) - 1) % mod * pow(x - 1, mod - 2, mod) % mod
	p[i + 1] = p[i] * (y + 1) % (mod - 1)
s = [1 for i in range(n + 1)]
for i in range(n - 1, -1, -1):
	s[i] = s[i + 1] * (a[i][1] + 1) % (mod - 1)
for i in range(n):
	z2 = z2 * pow(a[i][0], a[i][1] * (a[i][1] + 1) // 2 * p[i] * s[i + 1] % (mod - 1), mod) % mod
print(z0, z1, z2)
