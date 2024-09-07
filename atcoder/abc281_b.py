s = input()
if len(s) == 8 and s[0].isupper() and s[7].isupper() and s[1:7].isdigit() and s[1] > '0':
	print('Yes')
else:
	print('No')
