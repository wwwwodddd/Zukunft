a, b, x, y = map(int, input().split())
if a * 2 + b > x * 2 + y:
	print('Messi')
elif a * 2 + b < x * 2 + y:
	print('Ronaldo')
else:
	print('Equal')