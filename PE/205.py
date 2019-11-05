def F(n,m):
	f=[0]*37
	f[0]=1.
	for i in range(n):
		g=[0]*50
		for j in range(i*m+1):
			for k in range(1,m+1):
				g[j+k]+=f[j]/m
		f=g
	return f
a=F(6,6)
b=F(9,4)
z=0
for i in range(37):
	for j in range(i):
		z+=b[i]*a[j]
print "%.7f"%z
	
