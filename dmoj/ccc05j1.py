d = int(input())
e = int(input())
w = int(input())
a = max(d - 100, 0) * 25 + e * 15 + w * 20
b = max(d - 250, 0) * 45 + e * 35 + w * 25
print('Plan A costs %.2f' % (a / 100))
print('Plan B costs %.2f' % (b / 100))
if b < a:
	print('Plan B is cheapest.')
elif b > a:
	print('Plan A is cheapest.')
else:
	print('Plan A and B are the same price.')