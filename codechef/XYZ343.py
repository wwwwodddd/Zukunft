for t in range(int(input())):
	x, y, z = map(int, input().split())
	print(max(x - z // y, 0))