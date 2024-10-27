for t in range(int(input())):
	n = int(input())
	s = n * (n + 1) // 2
	b = 1
	while b <= n:
		s -= 2 * b
		b *= 2
	print(s)