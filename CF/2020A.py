for t in range(int(input())):
	n, k = map(int, input().split())
	if k == 1:
		print(n)
	else:
		s = 0
		while n > 0:
			s += n % k
			n //= k
		print(s)