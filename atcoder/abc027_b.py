n=int(input())
a=list(map(int,input().split()))
s=sum(a)
if s%n==0:
	a[0]-=s//n
	for i in range(1,n):
		a[i]+=a[i-1]-s//n
	print(n-a.count(0))
else:
	print(-1)