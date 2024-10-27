t = int(input())
for tt in range(t):
	a, x, b, y = map(int, input().split())
	if a * y > b * x:
		print('Alice')
	elif a * y < b * x:
		print('Bob')
	else:
		print('Equal')