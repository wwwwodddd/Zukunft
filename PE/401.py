def F(x):
	return x*(x+1)*(2*x+1)/6
n=input()
i=1
z=0
c=0
while i<=n:
	r=n/(n/i)
	c+=1
	if c%10000==0:
		print i,r
	z=(z+n/i*(F(r)-F(i-1)))%1000000000
	i=r+1
print z
