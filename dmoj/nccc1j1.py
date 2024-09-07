n = int(input()) + 1
a = list(str(n))
for i in range(len(a)):
	if a[i] == '0':
		for j in range(i, len(a)):
			a[i] = '1'
print(''.join(a))