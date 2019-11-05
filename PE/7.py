def P(x):
	for i in range(2,int(x**0.5)+1):
		if x%i==0:
			return 0
	return 1
c=0
n=input()
for i in xrange(2,10**7):
	if P(i):
		c+=1
	if c==n:
	 	print i
	 	break
