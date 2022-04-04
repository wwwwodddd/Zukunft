for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = sum(a)
	z = 1
	if s == 0:
		z = n
	else:
		for i in range(1, s + 1):
			if s % i == 0:
				f = True
				c = 0
				for j in a:
					c += j
					if c == i:
						c = 0
					elif c > i:
						f = False
						break
				if f:
					z = s // i
					break
	print(n - z)