import math
t1, t2, x1, x2, t0 = map(int, input().split())
t1 = t0 - t1
t2 = t2 - t0
z1 = 0
z2 = 0
if t1 == 0:
	z1 = x1
if t2 == 0:
	z2 = x2
if t1 != 0 and t2 != 0:
	z1 = 0
	z2 = x2
	for i2 in range(x2, -1, -1):
		i1 = min(i2 * t2 // t1, x1)
		if (i2 * t2 - i1 * t1) * (z1 + z2) < (z2 * t2 - z1 * t1) * (i1 + i2):
			z1 = i1
			z2 = i2
print(z1, z2)
