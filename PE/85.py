z=2000000
zi=0
zj=0
def F(x):
	return x*(x+1)/2
for i in xrange(2000):
	for j in xrange(2000):
		u=F(i)*F(j)
		if abs(u-2000000)<z:
			z=abs(u-2000000)
			zi=i
			zj=j
print zi,zj,zi*zj
print F(zi)*F(zj)

