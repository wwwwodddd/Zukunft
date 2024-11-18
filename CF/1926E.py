def F(n, k):
	if 2 * k - 1 <= n:
		return 2 * k - 1
	else:
		return F(n // 2, k - (n + 1) // 2) * 2
for t in range(int(input())):
	n, k = map(int, input().split())
	print(F(n, k))