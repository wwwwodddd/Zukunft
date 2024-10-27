for t in range(int(input())):
	n, p = map(int, input().split())
	f = [0 for i in range(n + 3)]
	f[0] = pow(n, n, p)
	f[n] = 1
	for l in range(1, n)[::-1]:
		f[l] = (f[l + 1] * (n - l) * 2 - f[l + 2] * (n - l - 1) * (n - l - 1)) % p
	for i in range(1, n + 1):
		for j in range(i):
			f[i] = f[i] * (n + 1 - max(j + 1, i - j)) % p
	for i in range(1, n + 1):
		f[i] = (f[i] - 2 * f[i + 1] + f[i + 2]) % p
		f[0] = (f[0] - f[i]) % p
	print(*f[:n+1])
