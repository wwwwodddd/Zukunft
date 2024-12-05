n = int(input())
a = [0, 0, 1, 1]
for i in range(4, n + 1):
	a.append(a[-3] + a[-2] * 2 + a[-1])
print(a[n])