a=[]
for i in range(2,1000):
	u=i
	while u<10**100:
		u=u*i
		if sum(map(int,list(str(u))))==i:
			a.append(u)
			print u
a=sorted(a)
print a[29]
