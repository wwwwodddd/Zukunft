for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	if n < 3:
		print(-1)
	else:
		print(max(a[n // 2] * n * 2 + 1 - sum(a), 0))