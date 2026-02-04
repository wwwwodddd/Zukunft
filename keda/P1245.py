n, k = map(int, input().split())
f = [0 for i in range(n + 1)]
f[0] = 1
for i in range(1, n + 1):
	for j in range(1, min(k + 1, i + 1)):
		f[i] = (f[i] + f[i - j]) % 1000000007
print(f[n])