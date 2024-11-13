for t in range(int(input())):
	x, y = map(int, input().split())
	if x >= 1000:
		print(x * y * 0.9)
	else:
		print(x * y * 1.0)