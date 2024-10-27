s = input()
if 'AB' not in s or 'BA' not in s:
	print('NO')
elif s.find('AB') + 2 <= s.rfind('BA') or s.find('BA') + 2 <= s.rfind('AB'):
	print('YES')
else:
	print('NO')