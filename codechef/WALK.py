for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(n - 2, -1, -1):
		a[i] = max(a[i], a[i + 1] + 1)
	print(a[0])