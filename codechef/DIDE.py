for t in range(int(input())):
	n, k = map(int, input().split())
	a = sorted(map(int, input().split()))
	for i in range(k):
		a[i] = max(a[i], 7 - a[i])
	print(sum(a))