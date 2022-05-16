while True:
	n = int(input())
	if n == 0:
		break
	if n == 1:
		print('{ }')
		continue
	n -= 1
	s = '{ '
	f = 0
	for i in range(64):
		if n >> i & 1:
			if f:
				s += ', '
			f = 1
			s += str(3 ** i)
	s += ' }'
	print(s)