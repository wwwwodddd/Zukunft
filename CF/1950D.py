f = [0 for i in range(100002)]
f[0] = f[1] = 1
for i in range(1, 10001):
	if f[i]:
		f[i * 10] = f[i * 10 + 1] = 1
for i in range(1, 100001):
	if f[i]:
		for j in range(i, 100001, i):
			if f[j // i]:
				f[j] = 1
for t in range(int(input())):
	if f[int(input())]:
		print('YES')
	else:
		print('NO')
