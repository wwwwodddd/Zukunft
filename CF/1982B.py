for t in range(int(input())):
	x, y, k = map(int, input().split())
	while k > 0:
		if x == 1:
			k %= y - 1
		t = min(y - x % y, k)
		x += t
		k -= t
		while x % y == 0:
			x //= y
	print(x)