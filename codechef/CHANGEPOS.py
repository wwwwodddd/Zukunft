for t in range(int(input())):
	a, b, c, d = map(int, input().split())
	if a != c and b != d:
		print(1)
	else:
		print(2)
