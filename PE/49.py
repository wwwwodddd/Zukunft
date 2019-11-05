from itertools import permutations
def P(x):
	if x<1000 or x>9999:
		return 0
	for i in range(2,int(x**0.5)+1):
		if x%i==0:
			return 0
	return 1
def do(a):
	for i in a:
		for j in a:
			if i!=j and 2*j-i in a:
				print i,j,2*j-i
for i in range(10):
	for j in range(i+1):
		for k in range(j+1):
			for l in range(k+1):
				a=[i,j,k,l]
				a=[int(''.join(map(str,w)))for w in permutations(a)]
				a=set(filter(P,a))
				do(a)
