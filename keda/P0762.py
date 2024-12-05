s = input()
if s[0] == '0':
	print(s)
	print(s)
elif s[0] == '1':
	a = list(s)
	for i in range(1, 32):
		a[i] = str(1 - int(a[i]))
	b = a.copy()
	for i in range(1, 32)[::-1]:
		if b[i] == '0':
			b[i] = '1'
			break
		else:
			b[i] = '0'
	print(''.join(a))
	print(''.join(b))