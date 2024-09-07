t = int(input())
for tt in range(t):
	n = int(input())
	a = [[1e9], [1e9], [1e9], [1e9]]
	for i in range(n):
		x, y = input().split()
		a[int(y, 2)].append(int(x))
	z = min(min(a[1]) + min(a[2]), min(a[3]))
	if z > 1e8:
		z = -1
	print(z)
