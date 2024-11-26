for t in range(int(input())):
	a, b, m = map(int, input().split())
	print(min(abs(a - b), m - abs(a - b)))
