for t in range(int(input())):
	a = input()
	b = input()
	n = len(a)
	a = a.count('1')
	b = b.count('1')
	c = min(a + b, 2 * n - a - b)
	print('1' * c + '0' * (n - c))
