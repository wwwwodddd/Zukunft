import math
for t in range(int(input())):
	n = int(input())
	a = list(range(1, n + 1))
	a.sort(key=lambda x: -math.gcd(x, n))
	print(*a)