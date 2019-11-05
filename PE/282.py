p=14**8
def phi(p):
	if p%2==0:
		p=p/2*1
	if p%3==0:
		p=p/3*2
	if p%7==0:
		p=p/7*6
	return p
def A(m,n):
	if m==0:
		return n+1
	if m==1:
		return n+2
	if m==2:
		return 2*n+3
	if m==3:
		return pow(2,n+3,p*phi(p)*phi(phi(p))*phi(phi(phi(p))))-3
	if n==0:
		return A(m-1,1)
	return A(m-1,A(m,n-1))
def F(x,p):
	if x==0:
		return 1
	if p==1:
		return 1
	u=F(x-1,phi(p))
	z=1
	for i in xrange(u):
		z*=2
		if z>=p:
			return pow(2,u,p)+p
	return z
s=0
for i in range(4):
	s+=A(i,i)
s+=F(7,p)-3
s+=F(1000,p)-3
s+=F(1000,p)-3
print s%p
