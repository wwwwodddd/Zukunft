p=10**8
def phi(p):
	if p%2==0:
		p=p/2*1
	if p%5==0:
		p=p/5*4
	return p
def F(x,p):
	print x,p
	if x==0:
		return 1
	if p==1:
		return 1
	u=F(x-1,phi(p))
	z=1
	for i in xrange(u):
		z*=1777
		if z>=p:
			return pow(1777,u,p)+p
	return z
print F(1855,p)%p
