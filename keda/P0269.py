x, m = map(int, input().split())
a = ''
if x == 0:
	a = '0'
while x > 0:
	a += '%X' % (x % m)
	x //= m
print(a[::-1])
