f = [3, 4, 6, 9]
for i in range(4, 10001):
	f.append(2 * f[-2] + f[-3] - f[-4])
f[0] = 0
for t in range(int(input())):
	print(f[int(input())])