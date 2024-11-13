import math
for t in range(int(input())):
	x, y = map(int, input().split())
	print(x - math.gcd(x, y))
