for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	i = 0
	for j in range(n):
		if a[i] + a[i + 1] <= a[j]:
			i += 1
	print(n - j + i - 1)