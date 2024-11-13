for t in range(int(input())):
	a, b = map(int, input().split())
	print(min(b, a - b))