s = input()
z = []
for i in s:
	if len(z) and (ord(z[-1])^ord(i)) == 32:
		z.pop()
	else:
		z.append(i)
if len(z) == 0:
	print('Empty')
else:
	print(''.join(z))
