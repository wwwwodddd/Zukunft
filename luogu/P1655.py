f = [[0 for i in range(101)]for i in range(101)]
f[0][0] = 1
for i in range(1, 101):
	for j in range(1, 101):
		f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j]
while True:
	try:
		n, m = map(int, input().split())
		print(f[n][m])
	except:
		break
