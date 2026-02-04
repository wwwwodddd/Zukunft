n = int(input())
f = [0 for i in range(n + 1)]
f[0] = 1
for i in [10, 20, 50, 100]:
	for j in range(i, n + 1):
		f[j] += f[j - i]
print(f[n])
