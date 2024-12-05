import math
a, b, c = map(int, input().split())
f = abs(a + b) // abs(c)
if a + b < 0:
	f = -f
if c < 0:
	f = -f
print(f)
