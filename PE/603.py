n = 10 ** 6
k = 10 ** 12
p = 10 ** 9 + 7
v = [0 for i in xrange(15485863 + 1)]
m = 0
cnt = 0
for i in xrange(2, 15485863 + 1):
	if v[i] > 0:
		continue
	m += len(str(i))
	cnt += 1
	for j in xrange(i, 15485863 + 1, i):
		v[j] = i
	if cnt == n:
		break


assert cnt == n
print m, cnt

b = m
ans = 0

mp10 = pow(10, m, p)
kmp10 = pow(10, k * m, p)
mkmp10 = pow(10, (m + k * m), p)
r2 = pow(2, p - 2, p)
r9 = pow(9, p - 2, p)
for i in xrange(2, 15485863 + 1):
	if v[i] == i:
		for j in str(i):
			tmp = -((pow(10, b, p) * (-(-1 + mp10) * (-1 + kmp10) + (-1 + mp10) * (-1 + kmp10) * b + (mp10 - mkmp10 - k + mp10 * k) * m)))
			
			tmp = tmp * pow((-1 + mp10) ** 2, p - 2, p) % p
			tmp = (tmp - (2 - 2 * b + m + k * m) * r2 * k) % p
			tmp = tmp * r9 % p
			b -= 1
			if b % 10000 == 0:
				print b
			ans = (ans + int(j) * tmp) % p
assert b == 0
print ans
