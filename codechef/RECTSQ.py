import math
for t in range(int(input())):
	n, m = map(int, input().split())
	g = math.gcd(n, m)
	print(n * m // g // g)
