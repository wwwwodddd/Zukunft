for t in range(int(input())):
	a, c, b, d = map(int, input().split())
	if a * a * d * d * d == c * c * b * b * b:
		print('Yes')
	else:
		print('No')
