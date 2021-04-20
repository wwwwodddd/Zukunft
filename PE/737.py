from math import *
i = 2
n = 1
u = 0
um = 0
xs = 1.0
ys = 0.0

while True:
	cx = xs / (i - 1)
	cy = ys / (i - 1)
	t = (atan2(cy, cx) + um) % (2 * pi)
	r = hypot(cx, cy)
	u += acos(r / 2) - t
	um = (um + acos(r / 2) - t) % (2 * pi)
	xs += cos(-um)
	ys += sin(-um)
	if u >= 2 * n * pi:
		print(n, i, u)
		n += 1
		if n > 2020:
			break
	i += 1