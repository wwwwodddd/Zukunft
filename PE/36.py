s=0
def F(x):
	s=str(x)
	b=bin(x)[2:]
	if s==s[::-1] and b==b[::-1]:
		return True
for i in xrange(1000000):
	if F(i):
		print i
		s+=i
print s
