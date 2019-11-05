f=[0]*60
f[0]=1
for i in range(1,52):
	f[i]=f[i-1]
	for j in range(4,i+1):
		f[i]+=f[i-j]

print f[51]
