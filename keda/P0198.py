z = 1
s = 1
for i in range(1, int(input()) + 1):
	s /= i
	z += s
print('%.10f' % z)