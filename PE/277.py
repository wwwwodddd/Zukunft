def F(x):
	s = ''
	while x > 1:
		if x % 3 == 0:
			s += 'D'
			x = x / 3
		elif x % 3 == 1:
			s += 'U'
			x = (4 * x + 2) / 3
		elif x % 3 == 2:
			s += 'd'
			x = (2 * x - 1) / 3

	return s


a = 'UDDDUdddDDUDDddDdDddDDUDDdUUDd'


#print F(122)
#for i in range(1, 10000):
#	if F(i)[:6] == 'UDDDUd':
#		print i, F(i), i % 729
n = len(a)
z = 1
for i in range(1, n):
	for j in range(3):
		t = F(z + j * 3 ** i)

		if i < len(t) and t[i] == a[i]:
			z = z + j * 3 ** i
			print z, t
			break
