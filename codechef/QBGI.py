for i in range(int(input())):
	input()
	b = g = 0
	for i in input():
		if i == 'G':
			g += 1
		else:
			b += 1
		if b > g * 2:
			break
	print(b + g)
