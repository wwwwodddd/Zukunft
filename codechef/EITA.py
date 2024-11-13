for t in range(int(input())):
	d, x, y, z = map(int, input().split())
	print(max(7 * x, d * y + (7 - d) * z))