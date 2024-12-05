n = int(input())
a = [list(map(int, input().split())) for i in range(n)]
z = 0
for i in range(n):
	for j in range(n):
		if i == j or i + j == n - 1:
			z += a[i][j]
print(z)
