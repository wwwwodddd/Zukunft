n=int(input())
for i in range(1,3501):
	for j in range(1,i+1):
		d=4*i*j-i*n-j*n
		if d>0 and i*j*n%d==0:
			print(i,j,i*j*n//d)
			exit()