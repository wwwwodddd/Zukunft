n, d = map(int, input().split())
f = [1] + [0 for i in range(d + 1)]
for i in range(d):
	f[i + 1] = f[i] ** n + 1
print(f[d] - f[d - 1])