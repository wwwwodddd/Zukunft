x, y = map(int, input().split())
if x < y:
	print('Old')
elif x > y:
	print('New')
else:
	print('Same')