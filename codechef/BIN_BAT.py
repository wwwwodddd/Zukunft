for t in range(int(input())):
	n, a, b = map(int, input().split())
	l = 0
	while 2 ** l < n:
		l += 1
	print(a * l + b * (l - 1))