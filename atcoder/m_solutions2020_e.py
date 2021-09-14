n=int(input())
a=[list(map(int,input().split()))for i in range(n)]
z=[10**12 for i in range(n + 1)]
def dfs(d,t,f):
	if d==n:
		z[t]=min(z[t],sum(f[i]*a[i][2]for i in range(n)))
		return
	dfs(d+1,t,f)
	dfs(d+1,t+1,[min(f[i],abs(a[i][0]-a[d][0]))for i in range(n)])
	dfs(d+1,t+1,[min(f[i],abs(a[i][1]-a[d][1]))for i in range(n)])
dfs(0,0,[min(abs(x),abs(y))for x,y,p in a])
for i in range(n + 1):
	print(z[i])