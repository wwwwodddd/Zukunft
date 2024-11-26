for t in range(int(input())):
	l, r, m = map(int, input().split())
	print(m // r + (m + l - 1) // l)