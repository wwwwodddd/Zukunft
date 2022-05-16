n = int(input())
if n < 5:
	print(n)
else:
	p = 1000000007
	print(pow(3, (n - 2) // 3, p) * ((n - 2) % 3 + 2) % p)