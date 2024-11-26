for t in range(int(input())):
	n = int(input())
	z = 0
	while n > 0:
		n -= int(n ** 0.5) ** 2
		z += 1
	print(z)