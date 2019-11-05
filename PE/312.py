# too slow
# DNF
def F(p):
	k=2
	c=0
	while True:
		if c%1000000==0:
			print c
		c+=1
		k=3*k**3%p
		if k==2:
			return c
a=F(13**8)
b=F(a)
c=F(b)
print a,b,c
