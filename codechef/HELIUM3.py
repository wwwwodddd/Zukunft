for t in range(int(input())):
	a, b, x, y = map(int, input().split())
	print(['No', 'Yes'][x * y >= a * b])
