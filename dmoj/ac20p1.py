for t in range(int(input())):
	a, b, c = sorted(map(int, input().split()))
	if a * a + b * b > c * c:
		print('A')
	elif a * a + b * b < c * c:
		print('O')
	else:
		print('R')