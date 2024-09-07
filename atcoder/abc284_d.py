t = int(input())
for tt in range(t):
	n = int(input())
	p = 2
	while n % p:
		p += 1
	n //= p
	if n % p:
		print(int((n) ** 0.5), p)
	else:
		print(p, n // p)
