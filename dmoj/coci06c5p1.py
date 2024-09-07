p = 1
for i in input():
	if i == 'A':
		if p == 1 or p == 2:
			p = 3 - p
	if i == 'B':
		if p == 2 or p == 3:
			p = 5 - p
	if i == 'C':
		if p == 1 or p == 3:
			p = 4 - p
print(p)