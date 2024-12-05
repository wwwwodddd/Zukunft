n, m = map(int, input().split())
z = -1e10
x = y = 0
for i in range(n):
	a = list(map(int, input().split()))
	for j in range(m):
		if z < a[j]:
			z = a[j]
			x = i
			y = j
print(z)
print(x + 1)
print(y + 1)