for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 2
	for i in range(1, n):
		z = min(z, a[i - 1] + a[i])
	print(sum(a) - 2 * z)