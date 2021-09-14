def F(n):
	z=0
	for i in range(n//4*4,n):
		z^=i
	return z
a,b=map(int,input().split())
print(F(b+1)^F(a))