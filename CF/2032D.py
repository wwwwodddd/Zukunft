import sys
for t in range(int(input())):
	n = int(input())
	p = [0 for i in range(n)]
	u = 1
	for i in range(2, n):
		if u > 1:
			while True:
				print('?', u, i)
				sys.stdout.flush()
				u += 1
				if int(input()) == 0:
					p[i] = u - 1
					break
		else:
			print('?', 1, i)
			sys.stdout.flush()
			if int(input()) == 0:
				p[i] = 1
				u = 2
	print('!', *p[1:])