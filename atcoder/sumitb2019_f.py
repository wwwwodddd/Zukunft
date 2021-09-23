t1, t2 = map(int, input().split())
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())
a1 -= b1
a2 -= b2
if a1 < 0:
	a1 = -a1
	a2 = -a2
a1 *= t1
a2 *= t2
if a1 > 0 and a1 + a2 > 0:
	print(0)
elif a1 == 0 or a1 + a2 == 0:
	print('infinity')
else:
	d = abs(a1 + a2)
	if a1 % d == 0:
		print(a1 // d * 2)
	else:
		print(a1 // d * 2 + 1)