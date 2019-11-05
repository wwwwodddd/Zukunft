n=input()
a=[0 for i in range(10)]
f=[1]*10
v=[0 for i in range(10)]
for i in range(1,10):
	f[i]=f[i-1]*i
for i in range(10):
	while v[a[i]]:
		a[i]+=1
	while n>f[9-i]:
		n-=f[9-i]
		a[i]+=1
		while v[a[i]]:
			a[i]+=1
	v[a[i]]=1
print ''.join(map(str,a))
