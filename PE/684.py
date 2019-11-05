mod = 1000000007
def S(n):
	s = 0
	for i in range(1, n + 1):
		t = i // 9
		s += (i % 9 + 1) * 10 ** t - 1
	return s % mod
def SS(n):
	s = 45 * (pow(10, n // 9, mod) - 1) * pow(9, -1, mod) % mod
	for i in range(n // 9 * 9, n + 1):
		t = i // 9
		s += (i % 9 + 1) * pow(10, t, mod)
	return (s - n - 1) % mod
#print(S(n))
f = [0 for i in range(91)]
f[1] = 1
ans = 0
for i in range(2, 91):
	f[i] = f[i-1] + f[i-2]
	ans = (ans + SS(f[i])) % mod
print(ans)
