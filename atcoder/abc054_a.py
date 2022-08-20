a, b = map(int, input().split())
a = (a + 11) % 13
b = (b + 11) % 13
if a > b:
	print('Alice')
elif a < b:
	print('Bob')
else:
	print('Draw')