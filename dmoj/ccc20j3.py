n = int(input())
xn = yn = 100
xm = ym = 0
for i in range(n):
	x, y = map(int, input().split(','))
	xn = min(xn, x)
	xm = max(xm, x)
	yn = min(yn, y)
	ym = max(ym, y)
print('%d,%d' % (xn-1,yn-1))
print('%d,%d' % (xm+1,ym+1))