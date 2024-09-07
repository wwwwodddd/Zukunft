n, m, y = input().split()
n = float(n)
m = float(m)
y = int(y)
for i in range(y + 1):
	print('%d %.2f' % (i, n))
	n *= 1 + m * 0.01