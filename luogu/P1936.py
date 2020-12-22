k = int(input())
m = n = 1
while n + m <= k:
	m, n = n, n + m
print('m=%d' % m)
print('n=%d' % n)