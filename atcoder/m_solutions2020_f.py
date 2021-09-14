n=int(input())
a=[]
for i in range(n):
	x,y,d=input().split()
	a.append((int(x),int(y),'RULD'.index(d)))
z=10**9
for j in range(4):
	b={}
	c={}
	for x,y,d in a:
		if d%2==0:
			if y not in b:
				b[y]=[]
			b[y].append((x,d))
		if d<2:
			if x+y not in c:
				c[x+y]=[]
			c[x+y].append((x,d))
	for d in b.values():
		l=-10**9
		for x,y in sorted(d):
			if y==0:
				l=x
			else:
				z=min(z,5*(x-l))
	for d in c.values():
		l=-10**9
		for x,y in sorted(d):
			if y==0:
				l=x
			else:
				z=min(z,10*(x-l))
	for i in range(n):
		a[i]=[-a[i][1],a[i][0],(a[i][2]+1)%4]
print([z,'SAFE'][z>1e8])