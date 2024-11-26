for t in range(int(input())):
	mt, mn, sn = map(int, input().split())
	z = mn ** 2 * min(sn // mn, mt)
	if sn // mn < mt:
		z += (sn % mn) ** 2
	print(z)