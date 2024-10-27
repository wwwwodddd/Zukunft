for t in range(int(input())):
	n, k = map(int, input().split())
	z = 0
	if n < k:
		z = k - n
		n = k
	if (k - n) & 1:
		n += 1
		z += 1
	print(z)