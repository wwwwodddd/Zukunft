n = 10 ** 18
z = 10 ** 9 - 2
i = 2

while i * i * i <= n:
	if i % 100000 == 0:
		print i
	for e in xrange(2, 64):
		if i ** e > n:
			break
#		if e == 2 and (i ** e) ** e > n:
#			break
		f = int(pow(i, 1. / e) + 0.5)
		if f ** e == i:
#			print f, e, i, 'continue'
			continue
		u = i
		a = [u]
		while True:
			u = u ** e
			if u > n:
				break
			for j in range(len(a)):
				if u + a[j] > n:
					break
				else:
					z += len(a)
					if e == 2 and j == 0:
						z -= 1
#					for k in range(len(a)):
#						if e == 2 and i == a[j] and i == a[k]:
#							continue
#						z += 1
#						print u + a[j], e, i, a[j], a[k]
			a.append(u)
	i += 1

print z