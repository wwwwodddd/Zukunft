z = 0
s = 0
n = int(input())
for i in range(n):
	if i & 1:
		s -= 2 * i + 1
	else:
		s += 2 * i + 1
	z += 1 / s
print('%.3f' % z)