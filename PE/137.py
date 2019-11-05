for i in range(1000):
	for j in range(1000):
		if i*i-5*j*j==20:
			print i,j,9*i+20*j,4*i+9*j
a=[]
x,y=5,1
for i in range(15):
	a.append(y)
	x,y=9*x+20*y,4*x+9*y
x,y=10,4
for i in range(15):
	a.append(y)
	x,y=9*x+20*y,4*x+9*y
x,y=25,11
for i in range(15):
	a.append(y)
	x,y=9*x+20*y,4*x+9*y
a=sorted(a)
a=filter(lambda i:i%5==1,a)
a=map(lambda i:i/5,a)
print a[15]
