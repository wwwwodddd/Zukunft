def C(x,y):
	z=1
	for i in range(y):
		z=z*(x-i)/(i+1)
	return z
f=[[0]*100 for i in range(100)]
g=[[0]*100 for i in range(100)]
for i in range(1,100):
	f[i][1]=1
	for j in range(2,100):
		f[i][j]=f[i][j-1]*C(i*j,i)

for i in range(1,100):
	for j in range(1,100):
		for k in range(1,i):
			if i%k==0:
				f[i][j]-=f[k][j]
for i in range(1,100):
	for j in range(1,100):
		f[i][j]/=i*j
for i in range(1,100):
	for j in range(1,100):
		for k in range(1,i+1):
			if i%k==0:
				g[i][j]+=f[k][j]
z=0
for i in range(1,100):
	for j in range(2,100):
		if g[i][j]<=10**15:
			z+=g[i][j]

print z
