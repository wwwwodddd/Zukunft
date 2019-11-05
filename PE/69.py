a=[2,3,5,7,11,13,17,19,23,27]
z=1
n=input()
for i in a:
	if z*i<=n:
		z*=i
print z
