x = y = z = 0
for i in input():
	if i == 'D':
		x += 1
	elif i == 'O':
		y += x
	elif i == 'G':
		z += y
print(z)