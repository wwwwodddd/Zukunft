from fractions import *
o=10**300
e=0
for i in range(1,200):
	e+=o
	o/=i
	if o==0:
		break
o=10**300
a=[0]*100
for i in range(100):
	a[i]=e/o
	e%=o
	e=o*o/e
n=100
z=Fraction(a[n-1],1)
for i in range(n-2,-1,-1):
	z=a[i]+1/z
print sum(map(int,list(str(z.numerator)))) 

