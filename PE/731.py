def A(n):
	z = 0
	m = 20
	for i in range(1, 100):
		if n + m - 3 ** i > 0:
			d = pow(10, n + m - 3 ** i, 10 ** (m + 1) * 3 ** i) // 3 ** i
			z += d
			# print(('%' + str(m + 1) + 'd') % d)
		else:
			break
	print('%010d' % (z % 10 ** (m + 1) // 10 ** 11))
A(100)
A(10**8)
A(10**16)