a, b = map(int, input().split())
if a < b:
	print('INCREASED')
elif a > b:
	print('DECREASED')
else:
	print('SAME')