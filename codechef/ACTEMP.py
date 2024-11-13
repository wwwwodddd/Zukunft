for t in range(int(input())):
	x, y, z = map(int, input().split())
	print(['No', 'Yes'][x <= y >= z])
