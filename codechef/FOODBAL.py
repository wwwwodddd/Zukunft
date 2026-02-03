f1, p1, f2, p2 = map(int, input().split())
if abs(f1 - p1) < abs(f2 - p2):
	print('First')
elif abs(f1 - p1) > abs(f2 - p2):
	print('Second')
else:
	print('Both')