n,d=map(int,input().split())
p=998244353
z=0
b=[0 for i in range(2000001)]
b[0]=1
for i in range(1,2000001):
	b[i]=b[i-1]*2%p
for i in range(d+1):
	# print(pow(2,max(i-1,0),p)*pow(2,max(d-i-1,0),p), (pow(2,n-max(i,d-i),p)-1))
	if n-max(i,d-i)>=0:
		z=(z+b[max(i-1,0)]*b[max(d-i-1,0)]*(b[n-max(i,d-i)]-1))%p
print(z*2%p)