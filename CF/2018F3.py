for t in range(int(input())):
	n, p = map(int, input().split())
 
	fac = [0 for i in range(n + 1)]
	fac[0] = 1
	for i in range(1, n + 1):
		fac[i] = fac[i - 1] * i % p
	invfac = [0 for i in range(n + 1)]
	invfac[n] = pow(fac[n], p - 2, p)
	for i in range(n)[::-1]:
		invfac[i] = invfac[i + 1] * (i + 1) % p
 
	f = [0 for i in range(n + 3)]
	f[0] = pow(n, n, p)
	f[n] = 1
	for l in range(1, n)[::-1]:
		f[l] = (f[l + 1] * (n - l) * 2 - f[l + 2] * (n - l - 1) * (n - l - 1)) % p
	for i in range(1, n + 1):
		f[i] = f[i] * fac[n - i + i // 2] * invfac[n - i] % p
		f[i] = f[i] * fac[n - i + (i + 1) // 2] * invfac[n - i] % p
	for i in range(1, n + 1):
		f[i] = (f[i] - 2 * f[i + 1] + f[i + 2]) % p
		f[0] = (f[0] - f[i]) % p
	print(*f[:n+1])