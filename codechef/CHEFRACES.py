for t in range(int(input())):
	x, y, a, b = input().split()
	print(len({x, y} - {a, b}))
