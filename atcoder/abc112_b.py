n, t = map(int, raw_input().split())
z = 9999
for i in range(n):
	a, b = map(int, raw_input().split())
	if b <= t:
		z = min(z, a)
if z == 9999:
	print 'TLE'
else:
	print z