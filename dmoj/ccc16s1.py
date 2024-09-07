c = {}
for i in input():
	if i not in c:
		c[i] = 0
	c[i] += 1
for i in input():
	if i not in c:
		c[i] = 0
	c[i] -= 1
for i in c:
	if i != '*' and c[i] < 0:
		print('N')
		break
else:
	print('A')