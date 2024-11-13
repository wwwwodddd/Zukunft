for t in range(int(input())):
	a, b, x = map(int, input().split())
	if a * b <= x * x:
		print(0)
	elif min(a, b) <= x * x:
		print(1)
	else:
		print(2)