n,k=map(int,input().split())
a=[list(map(int,input().split()))for i in range(n)]
k+=1
z=0
while k:
	z=max(z,sum(y for x,y in a if k-1&x==x))
	k&=k-1
print(z)