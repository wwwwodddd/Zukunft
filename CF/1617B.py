import math
for t in range(int(input())):
	n = int(input())
	i = 2
	while math.gcd(i, n - i - 1) > 1:
		i += 1
	print(n - i - 1, i, 1)