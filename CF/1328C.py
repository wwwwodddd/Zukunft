for t in range(int(input())):
	n = int(input())
	s = input()
	x = ''
	y = ''
	for i in range(n):
		if s[i] == '2':
			x += '1'
			y += '1'
		elif s[i] == '1':
			x += '1' + (n - i - 1) * '0'
			y += '0' + s[i + 1:]
			break
		elif s[i] == '0':
			x += '0'
			y += '0'
	print(x)
	print(y)