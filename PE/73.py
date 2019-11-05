from fractions import gcd
z=0
for i in range(12001):
	print i
	for j in range(i):
		if gcd(i,j)==1 and 2*j<=i and 3*j>=i:
			z+=1
print z-2
