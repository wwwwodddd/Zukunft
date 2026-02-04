n = int(input())
c = [0, 0, 0, 0]
for i in map(int, input().split()):
	if i < 19:
		c[0] += 1
	elif i < 36:
		c[1] += 1
	elif i < 61:
		c[2] += 1
	else:
		c[3] += 1
for i in c:
	print('%.2f%%' % (i / n * 100))