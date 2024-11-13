for t in range(int(input())):
	n, x = map(int, input().split())
	a = []
	if n & 1:
		a.append(x)
		n -= 1
	n //= 2
	a += range(x + 1, x + n + 1)
	a += range(x - n, x)
	print(*a)