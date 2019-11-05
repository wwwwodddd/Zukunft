from fractions import *
z=13
for i in range(5,100):
	z+=gcd(i,z)
	print i,z,z-3*i,z-i-1

