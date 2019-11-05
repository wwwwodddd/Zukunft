"""p=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]
n=input()
s=[0]*26
for i in xrange(2**25):
	if i%65536==0:
		print i
	c=0
	m=1
	for j in range(25):
		if i>>j and 1:
			c+=1
			m*=p[j]
	s[c]+=n/m
"""
q="""
10000000000000000
18028172010488700
13998605360669530
6288014611854466
1852825865389314
384760138516827
59005584090565
6905412892521
631674682648
45981299404
2698278047
127524585
4297997
46398
0
0
0
0
0
0
0
0
0
0
0
0
"""
def C(x,y):
	z=1
	for i in range(y):
		z=z*(x-i)/(i+1)
	return z
s=map(int,q.split())
print s
z=0
'''
for i in range(4,26):
	for j in range(4,i+1):
		if j%2:
			z-=C(i,j)*s[i]
		else:
			z+=C(i,j)*s[i]
'''
for j in range(4,26):
	for i in range(j-3):
		if i%2:
			z-=C(j,i)*s[j]
		else:
			z+=C(j,i)*s[j]
		print j,i,z
print z
