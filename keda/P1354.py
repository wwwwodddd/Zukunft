x = float(input())
if x >= 10:
	z = 2 * x + 1
elif x >= 0:
	z = 3 * x - 9
else:
	z = x - 9
print('%.2f' % z)