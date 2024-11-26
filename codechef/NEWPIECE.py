for t in range(int(input())):
	a, b, p, q = map(int, input().split())
	if a == p and b == q:
		print(0)
	elif (a + b + p + q) % 2:
		print(1)
	else:
		print(2)