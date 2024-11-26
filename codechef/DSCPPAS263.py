n, m = map(int, input().split())
if n * m % 2:
	print(-1)
else:
	for i in range(n):
		print(*([1] * m))