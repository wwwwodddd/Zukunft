n, m = map(int, input().split())
a = [0 for i in range(n + 1)]
for i in range(1, m + 1):
	for j in range(i, n + 1, i):
		a[j] ^= 1
print(','.join(map(str, [i for i in range(1, n + 1) if a[i]])))