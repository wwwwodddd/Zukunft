for t in range(int(input())):
	n = int(input())
	a = [100000000] + list(map(int, input().split()))
	for i in range(1, n):
		a[i] += a[i - 1]
	print(*a)