def C(x,y):
	z=1
	for i in range(y):
		z=z*(x-i)/(i+1)
	return z
n=input()
print C(n+9,9)+C(n+10,10)-10*n-2
