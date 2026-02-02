n = int(input())
a = [int(input()) - 1 for i in range(n)]
b = sorted(a)
c = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
for i in range(n):
	if a[i] != b[i]:
		c[a[i]][b[i]] += 1
z = 0
for i in range(3):
	t = min(c[i][(i + 1) % 3], c[(i + 1) % 3][i])
	c[i][(i + 1) % 3] -= t
	c[(i + 1) % 3][i] -= t
	z += t
print(z + max(c[0]) * 2)