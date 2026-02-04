n, m = map(int, input().split())
n -= 1
m -= 1
n += m
r = 1
for i in range(m):
	r = r * (n - i) // (i + 1)
print(r)