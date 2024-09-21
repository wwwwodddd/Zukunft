n = int(input())
a = range(1, n + 1)
z = []
d = 1
while len(a) > 1:
	z += a[d::2]
	a, d = a[1-d::2], (d + len(a)) % 2
z += a
print(*z)