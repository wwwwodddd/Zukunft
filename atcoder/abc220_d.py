n=int(input())
a=list(map(int,input().split()))
p=998244353
f=[0 for i in range(10)]
f[a[0]]=1
for i in a[1:]:
	g=[0 for i in range(10)]
	for j in range(10):
		g[(i+j)%10]=(g[(i+j)%10]+f[j])%p
		g[(i*j)%10]=(g[(i*j)%10]+f[j])%p
	f=g
for i in f:
	print(i)