def F(x):
	u=1
	while x>10**u/10*9*u:
		x-=10**u/10*9*u
		u+=1
	x-=1
	return int(str(x/u+10**u/10)[x%u])
z=1
for i in range(7):
	z*=F(10**i)
print z
