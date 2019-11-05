for i in range(1000):
	for j in range(1000-i):
		k=1000-i-j
		if i*i+j*j==k*k:
			print i,j,k,i*j*k
		elif i*i+j*j>k*k:
			break
