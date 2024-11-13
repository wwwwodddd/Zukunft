for t in range(int(input())):
	n = int(input())
	z = 0
	for i in range(0, n, 2):
		z += (n - i) ** 2
	print(z)
