f=[[[0]*10 for j in range(10)]for i in range(21)]
for i in range(10):
	for j in range(10):
		if i+j<10:
			f[2][i][j]=1
for i in range(3,21):
	for j in range(10):
		for k in range(10):
			for l in range(10):
				if j+k+l<10:
					f[i][l][j]+=f[i-1][j][k]
z=0
for i in range(1,10):
	for j in range(10):
		z+=f[20][i][j]
print z
