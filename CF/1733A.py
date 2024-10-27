for t in range(int(input())):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	for i in range(n):
		a[i % k] = max(a[i % k], a[i])
	print(sum(a[:k]))