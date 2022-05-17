n=int(input())+1
d=0
z=0
while 10**d<n:
	a=10**d
	b=min(10**(d+1),n)
	z+=(1+b-a)*(b-a)//2
	d+=1
print(z%998244353)