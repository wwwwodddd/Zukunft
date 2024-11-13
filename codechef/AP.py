for t in range(int(input())):
	x, y, z = map(int, input().split())
	print(int(x + z != y + y))
