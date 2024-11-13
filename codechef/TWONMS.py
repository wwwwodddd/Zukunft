for t in range(int(input())):
	a, b, n = map(int, input().split())
	if n & 1:
		a *= 2
	print(a // b)
