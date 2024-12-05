n, m = map(int, input().split())
z = 0
for i in range(n):
	a = list(map(int, input().split()))
	for j in range(m):
		if i == 0 or j == 0 or i == n - 1 or j == m - 1:
			z += a[j]
print(z)