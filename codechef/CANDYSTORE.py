for t in range(int(input())):
	x, y = map(int, input().split())
	if x < y:
		print(y + y - x)
	else:
		print(y)