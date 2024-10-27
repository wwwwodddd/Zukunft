import math
for t in range(int(input())):
	k = int(input())
	L = 0
	R = 10 ** 19
	while L < R - 1:
		M = (L + R) // 2
		if M - math.isqrt(M) < k:
			L = M
		else:
			R = M
	print(R)