for t in range(int(input())):
	x = int(input())
	s = 0
	z = 0
	while s < x:
		z += 1
		s += z
	if s == x + 1:
		print(z + 1)
	else:
		print(z)
