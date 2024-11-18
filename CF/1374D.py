import collections
for t in range(int(input())):
	n, k = map(int, input().split())
	c = collections.Counter()
	z = 0
	for i in map(int, input().split()):
		if i % k != 0:
			z = max(z, c[-i % k] * k + (-i % k + 1))
		c[-i % k] += 1
	print(z)