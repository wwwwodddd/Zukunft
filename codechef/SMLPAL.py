for t in range(int(input())):
	x, y = map(int, input().split())
	print('1' * (x // 2) + '2' * y + '1' * (x // 2))