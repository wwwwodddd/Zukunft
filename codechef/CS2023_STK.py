def F():
	z = c = 0
	for i in map(int, input().split()):
		if i:
			c += 1
		else:
			c = 0
		z = max(z, c)
	return z
for t in range(int(input())):
	n = input()
	a = F()
	b = F()
	if a < b:
		print('Addy')
	elif a > b:
		print('Om')
	else:
		print('Draw')