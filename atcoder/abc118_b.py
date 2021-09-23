n,m=map(int,input().split())
v=[0 for i in range(m+1)]
for i in range(n):
	for j in map(int,input().split()[1:]):
		v[j]+=1
print(v.count(n))