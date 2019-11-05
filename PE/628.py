p = 1008691207
n = 10 ** 8
f = 1
ans = 0
for i in range(n):
	ans += f * (n - i - 3)
	ans %= p
	f *= i + 1
	f %= p
ans += f
print (ans + 1) % p