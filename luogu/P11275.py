for t in range(int(input())):
	x, y = map(int, input().split())
	if x == y:
		print(0)
	elif y % x == 0:
		print(y)
	elif x % y == 0:
		print(x)
	else:
		print(x + y)