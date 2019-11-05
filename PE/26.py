z=0
w=0
for i in range(2,1000):
	k=i
	while k%2==0:
		k/=2
	while k%5==0:
		k/=5
	if k==1:
		continue
	for j in xrange(1,1000000):
		if pow(10,j,k)==1:
			if j>z:
				z=j
				w=i
			print i,j
			break
print w,z

