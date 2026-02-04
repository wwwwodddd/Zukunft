n = int(input())
f = [0 for i in range(n + 1)]
f[0] = 1
for i in range(1, n + 1):
	for j in range(i, n + 1):
		f[j] = (f[j] + f[j - i]) % 2147483648
print(f[n] - 1)