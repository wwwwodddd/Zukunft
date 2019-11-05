f=[1]*10
for i in range(1,10):
	f[i]=f[i-1]*i

z=0
for i in range(1000000):
	if i==sum(map(lambda x:f[x],map(int,list(str(i))))):
		print i
		z+=i
print z-3
