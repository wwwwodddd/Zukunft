for t in range(int(input())):
	n, x, y = map(int, input().split())
	s = input()
	if '0' in s and '1' in s:
		print(min(x, y))
	else:
		print(0)