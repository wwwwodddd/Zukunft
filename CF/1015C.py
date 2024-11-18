n, m = map(int, input().split())
a = []
for i in range(n):
	x, y = map(int, input().split())
	m -= y
	a.append(x - y)
a.sort()
i = 0
while i < n and m >= a[i]:
	m -= a[i]
	i += 1
if m < 0:
	print(-1)
else:
	print(n - i)