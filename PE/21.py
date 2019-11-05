def F(x):
	s=0
	for i in range(1,x):
		if x%i==0:
			s+=i
	return s
s=0
for i in range(2,10000):
	if i==F(F(i)) and i!=F(i):
		print i
		s+=i	
print s
