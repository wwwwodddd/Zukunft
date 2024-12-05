n, m, c, v = input().split()
n = int(n)
m = int(m)
v = int(v)
print(c * m)
for i in range(1, n - 1):
	if v:
		print(c * m)
	else:
		print(c + ' ' * (m - 2) + c)
print(c * m)
