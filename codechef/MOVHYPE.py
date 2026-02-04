t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	z = max(a[0], a[1])
	for i in range(n):
		z = min(z, max(a[i], a[i + 1]))
	print(z)