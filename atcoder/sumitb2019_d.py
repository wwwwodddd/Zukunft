n=int(input())
s=input()
f=[[-1 for i in range(10)]]
for i in range(n):
	f.append(f[i][:])
	f[-1][int(s[i])]=i
f.append(f[0][:])
z=0
for i in range(10):
	for j in range(10):
		for k in range(10):
			if f[f[f[n][i]][j]][k]>=0:
				z+=1
print(z)