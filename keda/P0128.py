z = []
for i in input():
	if i == '@':
		z = []
	elif i == '#':
		if z:
			z.pop()
	else:
		z.append(i)
print(''.join(z))
