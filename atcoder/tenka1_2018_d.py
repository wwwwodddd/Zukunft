n=int(input())
m=int((2*n)**0.5)+1
if m*(m-1)//2==n:
	print('Yes')
	print(m)
	a=[[]for i in range(m)]
	k=0
	for i in range(m):
		for j in range(i):
			k+=1
			a[i].append(k)
			a[j].append(k)
	for i in range(m):
		print(m-1,*a[i])
else:
	print('No')