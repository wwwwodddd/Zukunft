import math
k = 20000
n = 1000000


j = 0
s = 0
while 2 * j <= k:
	i = k - 2 * j
	t = 1.0
	l = 0
	for _ in range(i + j):
		l -= math.log(n)
		l += math.log(n - _)
#		t = t / n * (n - _)
#	print l, math.exp(l)
	for _ in range(j):
		l -= math.log(n)
		l += math.log(i + j + _ + 1)
		l -= math.log(_ + 1)
		l += math.log(i + _ + 1)
		l -= math.log(2)
	print j, l, math.exp(l), 1 - s
	s += math.exp(l)
	j += 1

print 1 - s