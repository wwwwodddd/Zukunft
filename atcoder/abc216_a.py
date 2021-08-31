s = input()
x = s[:-2]
y = int(s[-1])
if y < 3:
	print('%s-' % x)
elif y < 7:
	print('%s' % x)
else:
	print('%s+' % x)
