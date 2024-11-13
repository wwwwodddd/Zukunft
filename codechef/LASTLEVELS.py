for t in range(int(input())):
	x, y, z = map(int, input().split())
	print(x * y + (x - 1) // 3 * z)
