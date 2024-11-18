n, m = map(int, input().split())
r = [0 for i in range(n)]
c = [0 for j in range(m)]
for i in range(n):
	s = input()
	for j in range(m):
		if s[j] == 'S':
			r[i] = 1
			c[j] = 1
print(n * m - sum(r) * sum(c))
