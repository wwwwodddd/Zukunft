for t in range(int(input())):
	x, y, z = map(int, input().split())
	print(['Not now', 'Water filling time'][x + y + z < 2])
