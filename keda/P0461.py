n = int(input())
f = [i for i in range(n + 1)]
for i in [5, 11]:
	for j in range(i, n + 1):
		f[j] = min(f[j], f[j - i] + 1)
print(f[n])