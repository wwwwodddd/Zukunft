f=[0]*60000
c=[-1,1]
f[0]=1
for i in xrange(1,60000):
	if i%100==0:
		print i
	for k in xrange(1000):
		if k*(3*k-1)/2>i:
			break
		f[i]+=c[k%2]*f[i-k*(3*k-1)/2]
		if k*(3*k+1)/2<=i:
			f[i]+=c[k%2]*f[i-k*(3*k+1)/2]
		f[i]%=1000000
	if f[i]==0:
	 	print i
	 	break
