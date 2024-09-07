n = int(input())
f = []
for i in range(n):
	f.append(list(map(int, input().split())))
for i in range(n - 1)[::-1]:
	for j in range(i + 1):
		f[i][j] += max(f[i + 1][j], f[i + 1][j + 1])
print(f[0][0])