s = input()
z = ''
for i in s:
	if i == 'A':
		z += 'T'
	elif i == 'T':
		z += 'A'
	elif i == 'C':
		z += 'G'
	elif i == 'G':
		z += 'C'
print(z)