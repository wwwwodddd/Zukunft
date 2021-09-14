n,m,c=map(int,input().split())
b=list(map(int,input().split()))
z=0
for i in range(n):
	s=c
	a=list(map(int,input().split()))
	for i in range(m):
		s+=a[i]*b[i]
	z+=s>0
print(z)