def F(x):
	f=[0]*60
	f[0]=1
	for i in range(1,51):
		if i>0:
			f[i]+=f[i-1]
		if i>=x:
			f[i]+=f[i-x]
	return f[50]
print F(2)+F(3)+F(4)-3

