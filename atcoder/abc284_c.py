n, m = map(int, input().split())
f = [i for i in range(n + 1)]
def F(x):
	if f[x] == x:
		return x
	f[x] = F(f[x])
	return f[x]
for i in range(m):
	x, y = map(int, input().split())
	f[F(x)] = F(y)
z = 0
for i in range(1, n + 1):
	if f[i] == i:
		z += 1
print(z)
