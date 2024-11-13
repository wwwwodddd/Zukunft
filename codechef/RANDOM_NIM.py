p = 1000000007
for t in range(int(input())):
	n, d = map(int, input().split())
	input()
	print((d + 1) * pow(2 * d, p - 2, p) % p)