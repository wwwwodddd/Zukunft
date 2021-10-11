n,a,b=map(int,input().split())
z=0
for i in range(n+1):
	if a<=sum(int(j)for j in str(i))<=b:
		z+=i
print(z)