f = [0 for i in range(100)]
g = [0 for i in range(100)]
f[0] = 1
f[1] = 2
for i in range(2, 100):
	f[i] = f[i - 1] + f[i - 2]
def FF(n):
	re = 0
	for i in f[::-1]:
		if n >= i:
			n -= i
			re = i
	return re

def S(n):
	re = 0
	for i in range(1, n + 1):
		re += FF(i)
	return re

def SS(n):
	g[0] = 1
	g[1] = 3
	for i in range(2, 100):
		g[i] = g[i - 1] + g[i - 2] + f[i - 1]
	re = 0
	for i in range(100)[::-1]:
		if n >= f[i]:
			n -= f[i]
			re += g[i]
	return re

print SS(23416728348467685)
