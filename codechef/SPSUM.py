import math
for t in range(int(input())):
	n, m = map(int, input().split())
	s = n * (n + 1) // 2
	if s >= m and (s - m) % 2 == 0 and math.gcd((s - m) // 2, m) == 1:
		print('Yes')
	else:
		print('No')
