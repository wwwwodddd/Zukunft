n=int(input())
a=[]
z=0
for i in range(n):
	t,l,r=map(int,input().split())
	if t%2==0:
		r-=0.5
	if t>2:
		l+=0.5
	for x,y in a:
		if min(y,r)>=max(x,l):
			z+=1
	a.append((l,r))
print(z)