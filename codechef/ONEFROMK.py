for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	for i in range(n - 1, 0, -1):
		a[i - 1] += a[i]
	print(*a)
