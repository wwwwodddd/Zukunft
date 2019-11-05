s = set([i * i for i in range(3000)])
for xy in range(1, 1000):
#	print xy
	xy2 = xy ** 2
	for xz in range(1, xy):
		xz2 = xz ** 2
		for yz in range(1, xz):
			yz2 = yz ** 2
			if xy2 - xz2 in s and xy2 - yz2 in s and xz2 - yz2 in s:
				if (xy2 + xz2 + yz2) % 2 == 0:
					t = (xy2 + xz2 + yz2) / 2
					x = t - yz2
					y = t - xz2
					z = t - xy2
					if x + y in s and x - y in s and x + z in s and x - z in s and y + z in s and y - z in s:
						print x, y, z, x + y + z
