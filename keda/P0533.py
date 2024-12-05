x = float(input())
if x < 5:
	y = -x + 2.5
elif x < 10:
	y = 2 - 1.5 * (x - 3)
else:
	y = x / 2 - 1.5
print('%.3f' % y)