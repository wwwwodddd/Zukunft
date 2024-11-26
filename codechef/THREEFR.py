for t in range(int(input())):
	x, y, z = map(int, input().split())
	if 2 * max(x, y, z) == x + y + z:
		print('yes')
	else:
		print('no')
