for t in range(int(input())):
	b, c, d = map(int, input().split())
	a = b ^ d
	if (a | b) - (a & c) == d:
		print(a)
	else:
		print(-1)