for t in range(int(input())):
	n = int(input())
	s = 0
	for i in range(1, n):
		if n % i == 0:
			s += i
	if s < n:
		print(n, 'is a deficient number.')
	elif s > n:
		print(n, 'is an abundant number.')
	else:
		print(n, 'is a perfect number.')
