l = ''
c = 0
z = 0
for i in input():
	if l == i:
		c += 1
	else:
		c = 1
		l = i
	z = max(z, c)
print(z)