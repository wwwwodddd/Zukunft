n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
k = int(input())
z = 0
for i in range(n):
	for j in range(m):
		if a[i][j] > k:
			z += 1
print(z)