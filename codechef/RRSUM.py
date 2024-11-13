n, m = map(int, input().split())
for i in range(m):
	x = int(input())
	if x < n + 2:
		print(0)
	else:
		x -= n + 1
		if x <= n:
			print(x)
		else:
			print(2 * n - x)