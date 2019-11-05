from sage.all import *
def R(p):
	A = Integers(p)
	d = A(5)
	if d.is_square():
		x1 = (1 + d.sqrt()) / 2
		x2 = (1 - d.sqrt()) / 2
		if x1.multiplicative_order() == p - 1 or x2.multiplicative_order() == p - 1:
			return True
		else:
			return False
	return False

ans = []
cnt = 0
for i in primes(3, 10 ** 8):
	if R(i):
		ans.append(i)
	cnt += 1
	if cnt % 10000 == 0:
		print cnt, i
print sum(ans), len(ans)