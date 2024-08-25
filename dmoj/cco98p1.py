f = [0, 1]
for i in range(200):
	f.append(f[-1] + f[-2])
while True:
	n = int(input())
	if n == 0:
		break
	print(f[n])