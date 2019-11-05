p=1307674368000
def mul(a,b):
	c=[[0]*3 for i in range(3)]
	for i in range(3):
		for j in range(3):
			for k in range(3):
				c[i][j]+=a[i][k]*b[k][j]
				c[i][j]%=p
	return c	
def F(x,n):
	a=[[0,0,1],[0,0,0],[0,0,0]]
	b=[[x,1,0],[x*x,0,0],[x,0,1]]
	while n:
		if n&1:
			a=mul(a,b)
		n>>=1
		b=mul(b,b)
	return a[0][0]

n=input()
z=0
for i in range(101):
	print i
	z+=F(i,n)
print z%p
