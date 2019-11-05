z=[]
a=[1]
p=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]
n=10**9
def P(x):
	for i in xrange(2,int(x**0.5)+1):
		if x%i==0:
			return 0
	return 1
def F(x):
	x+=2
	while not P(x):
		x+=1
	return x
for i in p:
	b=[]
	for j in a:
		for k in range(1,100):
			if j*i**k>n:
				break
			b.append(j*i**k)
	a=b
	z+=a
ans=0
z=sorted(z)
print len(z)
s=[]
for i in z:
	if i%1000000==0:
		print i
	u=F(i)-i
	if u==131:
	  	print i
	s.append(u)
print set(s)
print sum(set(s))
