l, n, m = map(int, input().split())
a = []
for i in range(n):
	x, y = map(int, input().split())
	a.append([x, y])
b = []
for i in range(m):
	x, y = map(int, input().split())
	b.append([x, y])
i = 0
j = 0
z = 0
while i < n and j < m:
	t = min(a[i][1], b[j][1])
	if a[i][0] == b[j][0]:
		z += t
	a[i][1] -= t
	b[j][1] -= t
	if a[i][1] == 0:
		i += 1
	if b[j][1] == 0:
		j += 1
print(z)