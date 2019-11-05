def S(a, h):
	f = {};
	f[h] = 1
	for i in a:
		for j in range(a[i] + 1):
			