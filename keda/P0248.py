a = input()
b = input()
if a in b:
	print(a, 'is substring of', b)
elif b in a:
	print(b, 'is substring of', a)
else:
	print('No substring')
