a = list(map(int, input()))
if a[0] != 9:
	a[0] = min(a[0], 9 - a[0])
for i in range(1, len(a)):
	a[i] = min(a[i], 9 - a[i])
print(''.join(map(str, a)))
