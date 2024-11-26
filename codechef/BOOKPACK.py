for t in range(int(input())):
	x, y, z = map(int, input().split())
	print((y + z - 1) // z * x)
