import itertools
from functools import reduce 
import operator
def solve(n=65):
	ret = 0
	for a in range(n):
		b = int((n - a * a) ** 0.5)
		if a > b:
			break
		if a * a + b * b == n:
			ret += a
	return ret

def s(n=65):
	return solve(n)
	
prime = [5, 13, 17, 29, 37, 41, 53, 61, 73, 89, 97, 101, 109, 113, 137, 149]

def validN(prime):
	for i in range(2,len(prime)+1):
		for ee in itertools.combinations(prime,r=i):
			yield reduce(operator.mul, ee, 1)
print len(prime)
total = 0
cnt = 0
for N in validN(prime) :
	cnt += 1
	print cnt
	total += s(N)
print total