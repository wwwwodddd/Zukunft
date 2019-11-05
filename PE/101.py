def F(a):
	n=len(a)
	c=[[0]*(n+1)for i in range(n+1)]
	for i in range(n):
		c[0][i]=a[i]
	for i in range(1,n+1):
		for j in range(n-i):
			c[i][j]=c[i-1][j+1]-c[i-1][j]
	for i in range(n):
		c[n-i-1][i+1]=c[n-i-1][i]+c[n-i][i]
	for i in range(n+1):
		print c[i]
	return c[0][n]
def G(x):
	z=1
	for i in range(10):
		z=-x*z+1
	return z
c=[G(i) for i in range(1,12)]
s=0
for i in range(10):
	v=F(c[:i+1])
	s+=v
	print v
print s
		
