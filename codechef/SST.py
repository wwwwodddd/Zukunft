for t in range(int(input())):
	a, b = map(int, input().split())
	a *= 10
	b *= 5
	if a == b:
		print('ANY')
	elif a > b:
		print('FIRST')
	else:
		print('SECOND')
