x,y=2,1
while (y+1)/2<=10**12:
	print x,y,(x+2)/4,(y+1)/2
	x,y=3*x+4*y,2*x+3*y
print (x+2)/4,(y+1)/2
