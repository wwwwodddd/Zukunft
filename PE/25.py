f=[0]*10000
f[1]=1
for i in range(2,10000):
	f[i]=f[i-1]+f[i-2]
	if len(str(f[i]))==1000:
		print i
	if f[i]>10**999:
		print i
		break
