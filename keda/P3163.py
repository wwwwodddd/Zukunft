n, m = map(int, input().split())
f = [-1e9 for i in range(m + 1)]
f[0] = 0
for i in map(int, input().split()):
	for j in range(i, m + 1)[::-1]:
		f[j] = max(f[j], f[j - i] + 1)
if f[m] < 0:
	f[m] = -1
print(f[m])