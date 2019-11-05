n=input()
f=[[0,0,0] for i in range(n+1)]
g=[[0,0,0] for i in range(n+1)]
f[0][0]=1
for i in range(1,n+1):
	f[i][0]=f[i-1][0]+f[i-1][1]+f[i-1][2]
	f[i][1]=f[i-1][0]
	f[i][2]=f[i-1][1]
	g[i][0]=g[i-1][0]+g[i-1][1]+g[i-1][2]+f[i-1][0]+f[i-1][1]+f[i-1][2]
	g[i][1]=g[i-1][0]
	g[i][2]=g[i-1][1]
print f[n][0]+f[n][1]+f[n][2]+g[n][0]+g[n][1]+g[n][2]
