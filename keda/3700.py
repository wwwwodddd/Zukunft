n = int(input())
a = list(map(int, input().split()))
t = int(input())
f = [0 for i in range(t + 1)]
f[0] = 1
for i in range(1, t + 1):
	for j in a:
		if i >= j:
			f[i] += f[i - j]
for i in range(t + 1):
	print(i, f[i])
print(f[t])
