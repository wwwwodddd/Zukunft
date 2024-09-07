s = input()
l = 0
u = 0
d = 0
for i in s:
	if i.islower():
		l += 1
	if i.isupper():
		u += 1
	if i.isdigit():
		d += 1
if 8 <= len(s) <= 12 and l >= 3 and u >= 2 and d >= 1:
	print('Valid')
else:
	print('Invalid')