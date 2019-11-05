a=[]
def F(x,y):
	for i in range(30):
		if (x-7)%5==0:
			a.append((x-7)/5)
		x,y=9*x+20*y,4*x+9*y
F(7,1)
F(8,2)
F(13,5)
F(17,7)
F(32,14)
F(43,19)
print sum(sorted(a)[1:31])
