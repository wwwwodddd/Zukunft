f=[0]*220
f[0]=1
for i in range(1,200):
	f[i]=f[i-1]
	for j in range(51,i+1):
		f[i]+=f[i-j]
	if f[i]>=10**6:
	 	print i-1
	 	break

