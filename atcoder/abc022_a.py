n,s,t=map(int,input().split())
a=[int(input())for i in range(n)]
for i in range(1,n):
	a[i]+=a[i-1]
print(sum(s<=x<=t for x in a))