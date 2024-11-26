for t in range(int(input())):
	n = int(input())
	b = 1
	while b * 2 <= n:
		b *= 2
	b -= 1
	print((n ^ b) * b)