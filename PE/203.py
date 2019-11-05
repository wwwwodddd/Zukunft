n = 51
f = [[0 for i in range(n + 1)] for j in range(n + 1)]

a = []
for i in range(n):
	f[i][0] = 1
	for j in range(1, i + 1):
		f[i][j] = f[i - 1][j - 1] + f[i - 1][j]
	print f[i]
	a.extend(list(set(f[i])))
a = set(a)
s = 0
for i in a:
	for j in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]:
		if (i % (j * j) == 0):
			break
	else:
		s += i

print s