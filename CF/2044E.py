for t in range(int(input())):
	k, l1, r1, l2, r2 = map(int, input().split())
	z = 0
	while l2 <= r2:
		z += max(min(r1, r2) - max(l1, l2) + 1, 0)
		l2 = (l2 + k - 1) // k
		r2 = r2 // k
	print(z)