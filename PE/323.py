def C(x,y):
	z=1
	for i in range(y):
		z=z*(x-i)/(i+1)
	return z
f=[0]*40
for i in range(1,33):
	for j in range(i):
		f[i]+=f[j]*C(i,j)/2**i
	f[i]+=10**20
	f[i]=f[i]*2**i/(2**i-1)
print f[32]
