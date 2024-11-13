for t in range(int(input())):
	l, r = map(int, input().split())
	if ((r + 1) // 2 - l // 2) & 1:
		print('Odd')
	else:
		print('Even')