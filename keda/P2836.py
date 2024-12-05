t = int(input())
for tt in range(t):
	s = input()
	x = 0
	y = 0
	z = 0
	for i in s:
		if i == 'N':
			x += 1
			z += y
		elif i == 'S':
			x -= 1
			z -= y
		elif i == 'E':
			y += 1
			z -= x
		elif i == 'W':
			y -= 1
			z += x
	print('CCCWW'[z<0::2])