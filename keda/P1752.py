s = input()
if s.isdigit():
	print('数字字符')
elif s.islower():
	print('小写字母')
elif s.isupper():
	print('大写字母')
else:
	print('其它字符')