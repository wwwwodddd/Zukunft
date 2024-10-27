n = int(input())
L = 0
R = n * n
while L < R - 1:
	M = (L + R) // 2
	c = 0
	for i in range(1, n + 1):
		c += min(M // i, n)
	if c * 2 < n * n:
		L = M
	else:
		R = M
print(R)