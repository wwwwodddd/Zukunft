def F(n, k):
	if k <= (n + 1) // 2:
		return (k * 2 - 1) % n + 1
	z = F(n // 2, k - (n + 1) // 2)
	if n & 1:
		return z * 2 + 1
	else:
		return z * 2 - 1
for t in range(int(input())):
	n, k = map(int, input().split())
	print(F(n, k))