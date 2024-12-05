f = [0, 1, 3]
for i in range(3, 31):
	f.append(f[-1] * 3 - f[-2] * 2)
print(f[int(input())])