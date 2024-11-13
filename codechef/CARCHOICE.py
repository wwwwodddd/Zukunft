for t in range(int(input())):
	x1, x2, y1, y2 = map(int, input().split())
	if x1 * y2 > x2 * y1:
		print(-1)
	elif x1 * y2 < x2 * y1:
		print(1)
	else:
		print(0)