f = [1] + [0 for i in range(1000)]
for v in [10, 20, 50, 100]:
	for i in range(v, 1001):
		f[i] += f[i - v]
print(f[(int(input()))])