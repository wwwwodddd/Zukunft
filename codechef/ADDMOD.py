T = int(input())
for _ in range(T):
	N, P = map(int, input().split())

	def modinv(x):
		return pow(x, P-2, P)

	pow_term = pow(N, 2*N - 1, P)
	poly = N * (N*N - 1) % P
	poly = poly * modinv(6) % P

	ans = pow_term * poly % P
	print(ans)
