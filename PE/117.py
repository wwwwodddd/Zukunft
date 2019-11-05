f=[0]*60
f[0]=1
for i in range(1,51):
	if i>0:
		f[i]+=f[i-1]
	if i>1:
		f[i]+=f[i-2]
	if i>2:
		f[i]+=f[i-3]
	if i>3:
		f[i]+=f[i-4]
print f[50]
