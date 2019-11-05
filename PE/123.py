def P(x):
	for i in range(2,int(x**0.5)+1):
		if x%i==0:
			return 0
	return 1
c=0
for i in xrange(2,300000):
	if P(i):
		c+=1
		r=pow(i-1,c,i*i)+pow(i+1,c,i*i)
		r%=i*i
		print r
		if r>10000000000:
			print c
			break
