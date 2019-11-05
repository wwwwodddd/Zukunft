x=1
y=1
z=1
def T(x):
	return x*(x+1)/2
def P(x):
	return x*(3*x-1)/2
def H(x):
	return x*(2*x-1)
while True:
	u=max(T(x),P(y),H(z))
	if T(x)<u:
		x+=1
	elif P(y)<u:
		y+=1
	elif H(z)<u:
		z+=1
	else:
		print x,y,z,u
		x+=1
		y+=1
		z+=1
