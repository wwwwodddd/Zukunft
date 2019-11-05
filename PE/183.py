from math import log
from fractions import gcd
def F(n,k):
	return (log(n)-log(k))*k
n=input()
z=0
for i in range(5,n+1):
	p=i
	q=0
	for j in range(i/4,i/2+1):
		u=F(i,j)
		if u>q:
			q,p=u,j
	p/=gcd(p,i)
	while p%5==0:
	 	p/=5
	while p%2==0:
	 	p/=2
	if p==1:
		z-=i
	else:
	 	z+=i
	print i,p
print z
	
