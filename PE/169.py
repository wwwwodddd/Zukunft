n=input()
a=[]
for i in range(100):
	if n>>i&1:
		a.append(i)
print a
f=[0]*100
g=[0]*100
f[0]=a[0]
g[0]=1
for i in range(1,len(a)):
	f[i]=(a[i]-a[i-1])*f[i-1]+(a[i]-a[i-1]-1)*g[i-1]
	g[i]=f[i-1]+g[i-1]
print f
print g
print f[len(a)-1]+g[len(a)-1]
