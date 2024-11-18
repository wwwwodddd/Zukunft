for t in range(int(input())):
	p = 1000000007
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	z = 0
	s = 0
	for i in a:
		s = max(s + i, 0)
		z = max(z, s)
	print((sum(a) + z * (pow(2, k, p) - 1)) % p)