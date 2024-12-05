n = int(input())
c = 0
for i in range(n):
	z = ''
	for j in range(i + 1):
		c += 1
		z += '%4d' % c
	print(z)