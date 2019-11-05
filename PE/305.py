#DNF
def S(x, n):
	s = ''
	for i in range(1, min(n, 1000000)):
		s += str(i)
	ans = s.count(str(x))
	
def F(x):
	l=1
	while x>l*10**l/10*9:
		x-=l*10**l/10*9
		l+=1
#	print i,10**l/10+(x-1)/l
	return str(10**l/10+(x-1)/l)[(x-1)%l]
	print 5
for i in range(1, 13+1):
for i in range(1,100):
	print F(i)
