import math
for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	for i in range(1, len(a)):
		a[i] += a[i - 1]
	z = 0
	for i in range(len(a) - 1):
		z = max(z, math.gcd(a[i], a[-1]))
	print(z)