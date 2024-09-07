for t in range(int(input())):
	n = int(input())
	z = 1
	for i in range(1, min(n, 100) + 1):
		z = z * i % 4294967296
	print(z)