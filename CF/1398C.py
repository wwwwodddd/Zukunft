import collections
for t in range(int(input())):
	n = int(input())
	c = collections.Counter()
	c[0] = 1
	s = 0
	z = 0
	for i in map(int, input()):
		s += i - 1
		z += c[s]
		c[s] += 1
	print(z)