p = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59]
z = 1
for i in p:
	z *= i

def dfs(c, n, y, d):
	global z
	if z <= n:
		return
	if d == len(p):
		if c / 2 + 1 >= 4 * 10 ** 6:
			 z = n
		return
	t = 1
	for i in range(y + 1):
		dfs(c * (2 * i + 1), t * n, i, d + 1)
		t *= p[d]
		if t * n > z:
			return

dfs(1, 1, 1000, 0)
print z