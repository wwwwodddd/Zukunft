def P(x):
	for i in range(2,int(x**0.5)+1):
		if x%i==0:
			return 1
	return 0
n=input()
f=[0 for i in range(n+1)]
f[0]=1
for i in range(2,n):
	if not P(i):
		for j in range(i,n):
			f[j]+=f[j-i]
print f
for i in range(n):
	if f[i]>=5000:
		print i
		break

