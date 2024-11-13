x, y = input().split()
x = int(x)
y = float(y)
if x % 5 == 0 and y > x:
	print('%.2f' % (y - x - 0.5))
else:
	print('%.2f' % y)
