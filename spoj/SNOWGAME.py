from builtins import input
n, k = map(int, input().split())
if k == 1:
	print(n // 2)
elif k == 2:
	L = -1
	R = n
	while L < R - 1:
		M = (L + R) // 2
		if 2 * M * M + 1 < n:
			L = M
		else:
			R = M
	print(R)
elif k == 3:
	L = -1
	R = n
	while L < R - 1:
		M = (L + R) // 2
		if (((4 * M - 6) * M + 8) * M + 3) // 3 < n:
			L = M
		else:
			R = M
	print(R)
else:
	f = [1 for i in range(k + 1)]
	z = 0
	while f[k] < n:
		z += 1
		for i in range(k, 0, -1):
			f[i] += f[i - 1] * 2
	print(z)