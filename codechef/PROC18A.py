for t in range(int(input())):
	n, k = map(int, input().split())
	a = [0] + list(map(int, input().split()))
	for i in range(1, n + 1):
		a[i] += a[i - 1]
	print(max(a[i] - a[i - k] for i in range(k, n + 1)))