input()
s = input()
z = ''
for i in s:
	if i in 'aeiou':
		z += '0'
	else:
		z += '1'
print(z)