s = input().split('|')
c = 0
for i in s:
	if i[0] in 'ADE':
		c += 1
	elif i[0] in 'CFG':
		c -= 1
if c > 0 or c == 0 and s[-1][-1] in 'ADE':
	print('A-mol')
else:
	print('C-dur')