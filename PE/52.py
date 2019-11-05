def F(x):
	return sorted(list(str(x)))
for i in xrange(1,1000000):
	a=F(i)
	if a==F(2*i) and  a==F(3*i) and  a==F(4*i) and  a==F(5*i) and  a==F(6*i): 
		print i
		break
