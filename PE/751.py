from decimal import *
a = [0 for i in range(30)]
b = [0 for i in range(30)]
b[1] = Decimal('2.956938891377988')
b[1] = Decimal('2.223561019313554106173177195')
a[1] = int(b[1])
for i in range(2, 30):
	b[i] = a[i - 1] * (b[i - 1] - a[i - 1] + 1)
	a[i] = int(b[i])
print(a)
print('%.24f' % b[1])