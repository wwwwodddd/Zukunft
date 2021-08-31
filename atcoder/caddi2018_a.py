n,p=map(int,input().split())
i=2
a=[]
b=[]
while i*i<=p:
	if p%i==0:
		a.append(i)
		b.append(0)
		while p%i==0:
			p//=i
			b[-1]+=1
	i+=1
if p>1:
	a.append(p)
	b.append(1)
z=1
for i in range(len(a)):
	z*=a[i]**(b[i]//n)
print(z)