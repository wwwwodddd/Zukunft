n, t = map(int, input().split())
f = [0 for i in range(t + 1)]
f[0] = 1
for i in map(int, input().split()):
	for j in range(i, t + 1)[::-1]:
		f[j] += f[j - i]
print(f[t])