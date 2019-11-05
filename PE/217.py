f = [[0 for i in range(1000)] for j in range(30)]
g = [[0 for i in range(1000)] for j in range(30)]
f[0][0] = 1
g[0][0] = 0
for i in range(25):
	for j in range(i * 10 + 1):
		for k in range(10):
			f[i + 1][j + k] += f[i][j]
			g[i + 1][j + k] += g[i][j] * 10 + f[i][j] * k

#print f[1][1]

def R(n):
	if n == 1:
		return 45
	if n % 2 == 1:
		n /= 2
		ans = 0
		for i in range(10 * n + 1):
			ans += (g[n][i] - g[n - 1][i]) * 10 ** (n + 1) * 10 * f[n][i]
			ans += 45 * (f[n][i] - f[n - 1][i]) * f[n][i] * 10 ** n
			ans += g[n][i] * (f[n][i] - f[n - 1][i]) * 10
		return ans
	else:
		n /= 2
		ans = 0
		for i in range(10 * n + 1):
			ans += (g[n][i] - g[n - 1][i]) * 10 ** n * f[n][i]
			ans += g[n][i] * (f[n][i] - f[n - 1][i])
		return ans

def T(n):
	ans = 0
	for i in range(1, n + 1):
		ans += R(i)
	return ans

def S(n):
	cnt = 0
	summation = 0
	for i in range(10 ** (n - 1), 10 ** n):
		s = str(i)
		l = len(s) / 2
		first = sum(map(int, list(s[:l])))
		second = sum(map(int, list(s[-l:])))
		if first == second:
			cnt += 1
			summation += i
#			print i, first, second
	return cnt, summation
#print S(2)
#print R(2)
#for i in range(1, 48):
#	print i, T(i)
print T(47) % (3 ** 15)
#print 3 ** 15
# % (3 ** 15)
#print 334795890