from sage.all import *
def R(p):
	A = Integers(p ** 2)
	d = A(13)
	if d.is_square():
		x1 = (3 + d.sqrt()) / 2
		x2 = (3 - d.sqrt()) / 2
		x1 = int(x1)
		x2 = int(x2)
		return min(x1, x2)
	return 0

ans = 0
cnt = 0
for i in primes(3, 10 ** 7):
	ans += R(i)
	cnt += 1
	if cnt % 10000 == 0:
		print cnt, i
print ans