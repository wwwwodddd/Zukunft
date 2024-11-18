import math
for t in range(int(input())):
	a, b = map(int, input().split())
	if b % a == 0:
		print(b * b // a)
	else:
		print(math.lcm(a, b))