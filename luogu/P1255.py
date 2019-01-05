n = input()
x, y = 1, 0
for i in range(n):
	x, y = x + y, x
if n == 0:
	print 0
else:
	print x