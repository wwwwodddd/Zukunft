for t in range(int(input())):
	l, d, a, b, c = map(int, input().split())
	if l * d >= 42:
		print(c)
	elif l * d >= 21:
		print(b)
	elif l * d >= 10:
		print(a)
	else:
		print(0)