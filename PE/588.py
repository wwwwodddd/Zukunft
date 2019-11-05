def F(x):
	s = set([0])
	for i in range(70):
		if x >> i & 1:
			t = set([])
			for j in range(5):
				for k in s:
					u = k + (j << i)
					if u in t:
						t.remove(u)
					else:
						t.add(u)
#			print i, len(t)
			s = t
	return len(s)

def G(x):
	x = bin(x)[2:]
	a = x.split('00')
	re = 1
	for i in a:
		if i != '':
			t = F(eval('0b' + i))
#			print t, i
			re *= t
	return re

wocao = 0
for k in range(1, 19):
	nimabi = G(5 ** k)
#	print k, G(5 ** k)#, F(5 ** k)
	print k, nimabi
	wocao += nimabi

print wocao