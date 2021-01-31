a = [0] + list(map(int, input().split()))
d = []
for i in range(3):
	s, e = map(int, input().split())
	d.append((s, +1))
	d.append((e, -1))
d.sort()
z = s = 0
for i in range(5):
	s += d[i][1]
	z += (d[i + 1][0] - d[i][0]) * a[s] * s
print(z)