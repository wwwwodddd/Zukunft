'''
n + m - 3 + 5 * (m - 2) + 3 + 5 * (n - 2) + 1

n + m - 3 + (min(n, m) - 1) * 2 * 3 + (max(n, m) - min(n, m)) - 1

n == m
n + m - 3 + (n + m - 3) * 3 + 1
-11 + 4 m + 4 n

n > m

n + m - 3 + (2 * m - 2) * 3 + (n - m - 1) * 5 + 1
-13 + 2 m + 6 n

'''

n = 10 ** 6
v = [0 for i in range(n + 1)] 
for i in range(2, n + 1):
	if v[i] > 0:
		continue
	j = 0
	while j <= n:
		v[j] = i
		j += i

def F(x):
	while x % 8 > 0:
		x -= 6
	return x / 24 + 1

z = 0
for i in range(3, n + 1):
	if v[i] == i:
		s = i * i + 13
		z += 2 * F(s - 22)
print z