from fractions import *
n = 10 ** 8
# f = [0 for i in range(n + 1)]
# g = [0 for i in range(n + 1)]
# f[n] = 0
# g[n] = 0
# for i in range(n)[::-1]:
# 	f[i] = (f[i + 1] * (n - i) / n + 1) / (n - i) * n
# 	g[i] = (g[i + 1] * (n - i) / n + f[i]) / (n - i) * n
# 	print(i, f[i], g[i])
f = 0
g = 0
for i in range(n)[::-1]:
	f += 1 / (n - i) * n
	g += f / (n - i) * n
print(g / n)
# 18128250110.723045
# 18128250111
# 181282501104