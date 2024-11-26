for t in range(int(input())):
	e, k = map(int, input().split())
	z = 0
	while e > 0:
		e //= k
		z += 1
	print(z)