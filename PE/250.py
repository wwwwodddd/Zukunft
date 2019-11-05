c=[0]*250
p=10**16
for i in range(1,250251):
	c[pow(i,i,250)]+=1
print c
raw_input()
f=[pow(2,c[0],p)]+[0]*249
for i in range(1,250):
	print i
	g=[0]*250
	for j in range(250):
		for k in range(c[i]+1):
			g[(j+k*i)%250]=(g[(j+k*i)%250]+f[j])%p
	f=g
print f[0]-1
