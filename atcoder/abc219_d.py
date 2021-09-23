n = int(input())
x, y = map(int, input().split())
f = [[n + 1 for j in range(y + 1)]for i in range(x + 1)]
f[0][0] = 0
for i in range(n):
	a, b = map(int, input().split())
	for j in range(x + 1)[::-1]:
		for k in range(y + 1)[::-1]:
			f[min(j + a, x)][min(k + b, y)] = min(f[min(j + a, x)][min(k + b, y)], f[j][k] + 1)
if f[x][y] == n + 1:
	print(-1)
else:
	print(f[x][y])