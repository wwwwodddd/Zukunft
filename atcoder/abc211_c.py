f = [1] + [0] * 8
for i in input():
	j = 'chokudai'.find(i)
	if j != -1:
		f[j + 1] = (f[j + 1] + f[j]) % 1000000007
print(f[-1])