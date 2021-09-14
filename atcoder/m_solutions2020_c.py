n,m=map(int,input().split())
a=list(map(int,input().split()))
for i in range(m,n):
	print(['No','Yes'][a[i]>a[i-m]])