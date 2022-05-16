f = [[0 for j in range(7)]for i in range(501)]
f[0][0] = 1
for i in range(500):
	for j in range(7):
		for k in range(10):
			if k != 7:
				f[i + 1][(3 * j + k) % 7] += f[i][j]
for t in range(int(input())):
	n = int(input())
	print(10 ** n - sum(f[n][1:]) - 1)