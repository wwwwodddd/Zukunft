n, m = map(int, input().split())
f = [[[0, 0, 0] for j in range(m + 1)] for i in range(n + 1)]
# f[i][j][k] 前i局游戏，已经换了j次，最后一次出的是k
for i in range(n):
	# f[i] -> f[i + 1]
	c = input()
	if c == 'H':
		c = 2
	elif c == 'P':
		c = 1
	else:
		c = 0
	for j in range(m + 1):
		for k in [0, 1, 2]:
			f[i + 1][j][k] = f[i][j][k] + (c == k)
	for j in range(m):
		f[i + 1][j + 1][c] = max(f[i][j]) + 1
print(max(f[n][m]))
for i in range(n + 1):
	print(f[i])
