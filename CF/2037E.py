import sys
for t in range(int(input())):
	n = int(input())
	a = [0 for i in range(n + 1)]
	for i in range(2, n + 1):
		print('?', 1, i)
		sys.stdout.flush()
		a[i] = int(input())
	if n > 2:
		print('?', 2, n)
		sys.stdout.flush()
		b = int(input())
	else:
		b = 0
	if a[n] == 0:
		print('! IMPOSSIBLE')
		sys.stdout.flush()
	else:
		s = ['' for i in range(n + 1)]
		c0 = 1
		for i in range(3, n + 1)[::-1]:
			if a[i - 1] < a[i]:
				s[i] = '1'
				c0 = a[i] - a[i - 1]
			elif a[i] > 0:
				s[i] = '0'
				c0 -= 1
			else:
				if c0:
					assert c0 > 0
					s[i] = '0'
					c0 -= 1
				else:
					s[i] = '1'
		if b < a[n]:
			s[1] = '0'
			c0 -= 1
		else:
			s[1] = '1'
		if a[2] > 0:
			s[2] = '1'
		elif c0:
			s[2] = '0'
		else:
			s[2] = '1'
		print('!', ''.join(s))
		sys.stdout.flush()
