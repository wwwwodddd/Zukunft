s = input()
z = ''
for i in range(1, len(s) + 1):
	z += s[-i]
	if i % 3 == 0 and i < len(s):
		z += ','
print(z[::-1])