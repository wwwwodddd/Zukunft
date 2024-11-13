for t in range(int(input())):
	n = int(input())
	z = 0
	if n >= 4:
		z += n // 4 * 44 + (4 - n % 4) * 4
	if n % 4 == 1:
		z += 20
	elif n % 4 == 2:
		z += 36
	elif n % 4 == 3:
		z += 51
	print(z)