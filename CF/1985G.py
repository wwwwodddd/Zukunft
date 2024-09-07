p = 1000000007
for t in range(int(input())):
	l, r, k = map(int, input().split())
	d = 9 // k + 1
	print((pow(d, r, p) - pow(d, l, p)) % p)