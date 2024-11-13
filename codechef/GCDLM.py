import math
for t in range(int(input())):
	x, y, k = map(int, input().split())
	g = math.gcd(x, y)
	if k == 1:
		print(min(x, y) + g)
	else:
		print(2 * g)