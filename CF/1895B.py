for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	print(a[2 * n - 1] - a[n] + a[n - 1] - a[0])
	for i in range(n):
		print(a[i], a[i + n])
