def P(x):
	if x<2:
		return 0
	for i in range(2,int(x**0.5)+1):
		if x%i==0:
			return 0
	return 1
def F(x):
	if x==2 or x==5:
		return -1
	z=1
	re=1
	while True:
		z=(10*z+1)%x
		re+=1
		if z==0:
			return re
ans=0
for i in range(input()):
	if P(i):
		u=F(i)
#		print i,u
		while u%2==0:
			u/=2
		while u%5==0:
			u/=5
		if u!=1:
			print i
			ans+=i
print ans

