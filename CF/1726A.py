for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = a[n - 1] - a[0]
	if n > 1:
		z = max(z, a[n - 1] - min(a[:-1]), max(a[1:]) - a[0])
	for i in range(1, n):
		z = max(z, a[i - 1] - a[i])
	print(z)