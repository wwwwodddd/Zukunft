n = 100
f = [0 for i in range(n + 1)]
for i in range(1, n + 1):
	v = {f[i - 1]}
	if i % 2 == 0:
		v.add(f[i // 2])
	while f[i] in v:
		f[i] += 1
	print(i, f[i])