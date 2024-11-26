for t in range(int(input())):
	x, a, b = map(int, input().split())
	print(((100 - x) * b + a) * 10)
