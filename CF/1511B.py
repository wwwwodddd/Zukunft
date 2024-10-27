for t in range(int(input())):
	a, b, c = map(int, input().split())
	a -= 1
	b -= 1
	c -= 1
	if a < b:
		print(10 ** a, 10 ** a + 10 ** b + 10 ** c)
	else:
		print(10 ** a + 10 ** b + 10 ** c, 10 ** b)
