for t in range(int(input())):
	a, b = map(int, input().split())
	print('YNEOS'[a+b&1::2])