import collections
for t in range(int(input())):
	n, x = map(int, input().split())
	c = collections.Counter(map(int, input().split()))
	z = 0
	while c[z]:
		c[z + x] += c[z] - 1
		z += 1
	print(z)
