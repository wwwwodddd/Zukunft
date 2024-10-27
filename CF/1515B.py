import math
for t in range(int(input())):
	n = int(input())
	if n % 2 == 0 and math.isqrt(n // 2) ** 2 * 2 == n:
		print('YES')
	elif n % 4 == 0 and math.isqrt(n // 4) ** 2 * 4 == n:
		print('YES')
	else:
		print('NO')