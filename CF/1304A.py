import math
for t in range(int(input())):
	x, y, a, b = map(int, input().split())
	if (y - x) % (a + b) == 0:
		print((y - x) // (a + b))
	else:
		print(-1)
