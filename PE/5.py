from fractions import gcd
def lcm(x,y):
	return x/gcd(x,y)*y
print reduce(lcm,range(1,input()+1))
