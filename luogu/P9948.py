def F(t, x):
	if t <= x:
		return t * (t + 1) // 2
	t += x - 1
	t1 = t // 2
	t2 = t - t1
	return t1 * (t1 + 1) // 2 + t2 * (t2 + 1) // 2 - x * (x - 1) // 2
k, n = map(int, input().split())
for i in range(n):
	x = int(input())
	L = 0
	R = k
	while L < R - 1:
		M = (L + R) // 2
		if F(M, x) >= k:
			R = M
		else:
			L = M
	print(R)