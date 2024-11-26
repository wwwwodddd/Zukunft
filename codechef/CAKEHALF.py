for t in range(int(input())):
	a, b = map(int, input().split())
	s = a + b
	while a != b:
		if a > b:
			a //= 2
		else:
			b //= 2
	print(s - a - b)