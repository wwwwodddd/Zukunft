import collections
for t in range(int(input())):
	n = int(input())
	a = [list(map(int, input().split())) for i in range(n)]
	b = [0 for i in range(2 * n)]
	for i in range(n):
		for j in range(n):
			b[i - j] += a[i][j]
	print(max(b))