f=[1,2]+[0]*100
for i in range(2,102):
	f[i]=f[i-1]+f[i-2]
ans=0
for i in range(102):
	if f[i]<4*10**6 and f[i]%2==0:
		ans+=f[i]
print ans
