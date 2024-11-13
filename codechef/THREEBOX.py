import math
for t in range(int(input())):
	a, b, c, d = map(int, input().split())
	a, b, c = sorted([a, b, c])
	if a + b + c <= d:
		print(1)
	elif a + b <= d:
		print(2)
	else:
		print(3)