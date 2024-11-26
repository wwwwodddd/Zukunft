for t in range(int(input())):
	g1, s1, b1, g2, s2, b2 = map(int, input().split())
	if g1 + s1 + b1 > g2 + s2 + b2:
		print(1)
	else:
		print(2)