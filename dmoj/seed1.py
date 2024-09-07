s = ''.join(set('BFTLC') - set(input()))
if s:
	print(s)
else:
	print('NO MISSING PARTS')
