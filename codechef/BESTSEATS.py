for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = a[0] + a[1]
	for i in range(1, n):
		z = min(z, a[i] + a[i - 1])
	print(z)