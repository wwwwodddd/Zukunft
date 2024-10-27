for t in range(int(input())):
	n, k = map(int, input().split())
	z = 0
	for i in range(1, k + 1):
		z = max(z, n % i)
	print(z)