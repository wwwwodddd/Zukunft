for t in range(int(input())):
	a, b, c = map(int, input().split())
	x = abs(a - 1)
	y = abs(b - c) + (c - 1)
	if x < y:
		print(1)
	elif x > y:
		print(2)
	else:
		print(3)