def F(n):
	s=1
	for i in range(1,n+1):
		s*=(n*i)**i
	for i in range(n*(n+1)/2):
		s/=n*(n+1)/2
	return s
print sum(map(F,range(2,16)))
