for t in range(int(input())):
	n, k = map(int, input().split())
	z = 0
	while k > 0:
		t = min(n, k)
		if k - t & 1:
			t -= 1
		z += t
		k -= t
		k //= 2
	print(z)
