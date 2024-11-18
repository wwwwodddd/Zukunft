for t in range(int(input())):
	n = int(input())
	z = 0
	while n > 0:
		z += n
		n //= 2
	print(z)