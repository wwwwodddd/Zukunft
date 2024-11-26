for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = a[0] + a[-1]
	for i in range(1, n):
		z = max(z, a[i - 1] + a[i])
	print(z)