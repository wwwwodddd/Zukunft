for t in range(int(input())):
	x, y = map(int, input().split())
	if x + 2 * y <= 50 and 50 <= x + 2 * y + 10:
		print('Yes')
	else:
		print('No')