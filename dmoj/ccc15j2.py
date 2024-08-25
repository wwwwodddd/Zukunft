s = input()
x = s.count(':-)')
y = s.count(':-(')
if x == 0 and y == 0:
	print('none')
elif x == y:
	print('unsure')
elif x > y:
	print('happy')
else:
	print('sad')