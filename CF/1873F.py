for t in range(int(input())):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	h = list(map(int, input().split()))
	l = 0
	r = 0
	s = 0
	z = 0
	while r < n:
		if l < r and h[r - 1] % h[r]:
			l = r
			s = a[r]
		else:
			s += a[r]
		while s > k:
			s -= a[l]
			l += 1
		z = max(z, r - l + 1)
		r += 1
	print(z)
