for t in range(int(input())):
	x, y, z = map(int, input().split())
	print(min(10 * x, y) * z)