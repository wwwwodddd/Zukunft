for t in range(int(input())):
	n, x = map(int, input().split())
	a = [0] + list(map(int, input().split()))
	z = (x - a[n]) * 2
	for i in range(1, n + 1):
		z = max(z, a[i] - a[i - 1])
	print(z)