for t in range(int(input())):
	n = int(input())
	z = 0
	while n > 0:
		n //= 5
		z += n
	print(z)
