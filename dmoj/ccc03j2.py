while True:
	n = int(input())
	if n == 0:
		break
	i = int(n ** 0.5)
	while n % i:
		i -= 1
	print('Minimum perimeter is %d with dimensions %d x %d' % ((n // i + i) * 2, i, n // i))