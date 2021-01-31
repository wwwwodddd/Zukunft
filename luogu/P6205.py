n, m = map(int, input().split());
f = [1] + [0] * n
for i in range(1, m + 1):
	for j in range(i, n + 1):
		f[j] += f[j - i]
print(f[n])