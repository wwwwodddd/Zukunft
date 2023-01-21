n, m = map(int, input().split())
a = [[] for i in range(n + 1)]
for i in range(m):
	x, y = map(int, input().split())
	a[x].append(y)
	a[y].append(x)
p = []
for i in range(n):
	p.append(int(input()))
f = [i for i in range(n + 1)]
def F(x):
	if f[x] == x:
		return x
	f[x] = F(f[x])
	return f[x]

v = [False for i in range(n + 1)]
z = ['' for i in range(n)]
s = 0
for i in range(n)[::-1]:
	v[p[i]] = True
	s += 1
	for j in a[p[i]]:
		if v[j] and F(j) != F(p[i]):
			f[F(j)] = F(p[i])
			s -= 1
	if s == 1:
		z[i] = 'YES'
	else:
		z[i] = 'NO'
for i in range(n):
	print(z[i])
