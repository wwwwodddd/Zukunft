n=input()
z=0
for i in range(10**(n-1),10**n):
	for j in range(10**(n-1),10**n):
		k=str(i*j)
		if k==k[::-1]:
			z=max(z,int(k))
print z
