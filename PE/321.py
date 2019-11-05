a=[]
x,y=16,11
for i in range(20):
	a.append(x-4>>2)
	x,y=3*x+4*y,2*x+3*y
x,y=8,5
for i in range(20):
	a.append(x-4>>2)
	x,y=3*x+4*y,2*x+3*y
print a
print sum(a)

