p = 10 ** 16
c = [[0 for j in range(2021)]for i in range(2021)]
for i in range(2021):
	c[i][0] = 1
	for j in range(1, i + 1):
		c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p

def S(n):
	f = [[[0 for k in range(n)]for j in range(10)]for i in range(10)]
	for j in range(n):
		f[0][0][j] = 1
	for i in range(1, 10):
		for j in range(10):
			for k in range(n):
				for l in range(10):
					if j + i * l >= 10 or k + l >= n:
						break
					f[i][j + i * l][k + l] = (f[i][j + i * l][k + l] + f[i - 1][j][k] * c[k + l][l]) % p
	r = 0
	for j in range(10):
		r = (r + (f[9][j][n - 1] * 2 - (n - 1)) * j) % p
	return r * (10 ** n // 9) % p

print(S(3)) # 63270
print(S(7)) # 85499991450
print(S(2020))

