for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	f = [0 for i in range(n + 1)]
	for i in range(1, n + 1):
		if i - a[i - 1] >= 0:
			f[i] = f[i - a[i - 1]] + 1
	print(max(f))