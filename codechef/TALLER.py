for t in range(int(input())):
	x, y = map(int, input().split())
	print('AB'[x < y])