f = [0, 1, 2]
for i in range(3, 1001):
	f.append((f[-1] * 3 + f[-2] * 2) % 49999)
print(f[int(input())])