from fractions import *
z=Fraction(1)
c=0
for i in range(input()):
	z=1+1/(1+z)
	print z
	if len(str(z.numerator))>len(str(z.denominator)):
		c+=1
print c
