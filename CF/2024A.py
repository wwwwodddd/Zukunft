for t in range(int(input())):
	a, b = map(int, input().split())
	if a >= b:
		print(a)
	else:
		print(max(2 * a - b, 0))