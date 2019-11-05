def F(x):
	a,b=1,1
	x=str(x)
	for i in range(len(x)-1):
		a&=x[i]>=x[i+1]
		b&=x[i]<=x[i+1]
	return a or b
x,y=0,0
for i in xrange(1,100000000):
	if i%10000==0:
		print x,y
	if F(i):
		x+=1
	else:
	 	y+=1
	if y>=99*x:
	 	print i
	 	break
