for t in range(int(input())):
	l, r = map(int, input().split())
	L, R = map(int, input().split())
	z = min(r, R) - max(l, L) + 2 - (l == L) - (r == R)
	z = max(z, 1)
	print(z)