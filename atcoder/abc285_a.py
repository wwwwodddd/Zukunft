a, b = map(int, input().split())
if a > b:
	a, b = b, a
if b // 2 == a:
	print('Yes')
else:
	print('No')
