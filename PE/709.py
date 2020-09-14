from sage.all import *




#for k in range(0, n + 1)
n = 24680
p = 1020202009

A = Integers(p)
R = PolynomialRing(A, 'x');
x = R.gen()

fac = [0 for i in range(n + 1)]
fac[0] = 1
for i in range(1, n + 1):
	fac[i] = fac[i-1] * i % p

b = [0 for i in range(n + 2)]
for k in range(n + 1):
	if k % 2 == 0:
		b[n - k + 1] = pow(fac[k], p - 2, p)
b = R(b)

f = 1

for i in range(n):
	if i % 100 == 0:
		print(i)
	g = f * b
	f = 0
	g = g.list()
	f = R([g[j + n] * j for j in range(i + 2)])
	# print(f)

ans = 0
for i in range(n + 1):
	ans += f[i] * pow(fac[i], p - 2, p)
#print(sum(f))
print(ans % p)

# fac = [0 for i in range(n + 1)]
# fac[0] = 1
# for i in range(1, n + 1):
# 	fac[i] = fac[i-1] * i

# b = [0 for i in range(n + 2)]
# for k in range(n + 1):
# 	if k % 2 == 0:
# 		b[n - k + 1] = pow(fac[k], p - 2, p)

# f = [0 for i in range(n + 1)]
# f[0] = 1
# for i in range(n):
# 	g = [0 for j in range(2 * n + 2)]
# 	for j in range(n + 1):
# 		for k in range(n + 2):
# 			g[j + k] += f[j] * b[k]
# 	for j in range(n + 1):
# 		f[j] = g[j + n] * j
# 	print(f)

# ans = 0
# for i in range(n + 1):
# 	ans += f[i] * pow(fac[i], p - 2, p)
# #print(sum(f))
# print(ans % p)