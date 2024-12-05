k, r = map(float, input().split())
if k == 1:
	p = 3.14
else:
	p = 3.1415926
print('%.2f' % (r ** 3 * p * 4 / 3))