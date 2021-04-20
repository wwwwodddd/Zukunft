d = 2
z = []
def F(n):
	s = str(n)
	for k in range(60):
		t = sum(int(i) ** k for i in s)
		if t == n - 1 or t == n + 1:
			return k
		if t > n + 1:
			return 0
	return 0

def dfs(x, y, s, a):
	global z
	if x == 10:
		if y == d and s > 10:
			k = F(s + 1)
			if k:
				z.append(s + 1)
				print(s + 1, s, a, k)
			k = F(s - 1)
			if k:
				z.append(s - 1)
				print(s - 1, s, a, k)
	else:
		for i in range(d - y + 1):
			dfs(x + 1, y + i, s + x ** d * i, a + [i])


# dfs(0, 0, 0, [])
for d in range(2, 16 + 1):
	dfs(0, 0, 0, [])

print(sum(set(z)))
# 13459471903176422
exit()

z = 0
for i in range(1, 10000000000):
	f = F(i)
	if f == i - 1 or f == i + 1:
		z += i
		print(i, f, z)
print(z)