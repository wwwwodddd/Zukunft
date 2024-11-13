for t in range(int(input())):
	x, y = map(int, input().split())
	print(['Bob', 'Alice'][x + y in [2, 3, 5, 7, 11]])
