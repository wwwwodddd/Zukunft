p = 10 ** 9
def F(n):
	z = 3
	s = 0
	a = [n >> i & 1 for i in range(6)]
#	for i in range(100):
	while sum(a) > 0:
		print a
		if a[0] > 0:
			s += a[0]
			z += a[0]
			a[0] = 0
		elif a[1] > 0:
			s += z
			z += z
			a[1] -= 1
		elif a[2] > 0:
			a[2] -= 1
			s += z * (pow(2, z, p) - 1) % p
			z = z * pow(2, z, p) % p
		else:
			for i in range(6):
				if a[i] > 0:
					break
			a[i] -= 1
			for j in range(i):
				a[j] = z - 1
			z += 1
			s += 1

#	print a
	return s % p
n = 16
s = 0
#print F(2)
for i in range(1, n):
	s += F(i)
print s % p