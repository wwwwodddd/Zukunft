t = int(input())
p = 1000000007
for tt in range(t):
	n = int(input())
	print((pow(4, n, p) - pow(3, n, p) * 2 + pow(2, n, p)) % p)