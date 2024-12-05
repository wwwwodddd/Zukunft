z = 0
s = 0
n = int(input())
for i in range(n):
	s += 2 * i + 1
	z += 1 / s
print('%.6f' % z)