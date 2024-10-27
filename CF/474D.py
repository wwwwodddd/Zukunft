p = 1000000007
n = 100001
t, k = map(int, input().split())
f = [0 for i in range(n)]
for i in range(k):
	f[i] = i + 1
for i in range(k, n):
	f[i] = (f[i - 1] + f[i - k] + 1) % p
for i in range(t):
	x, y = map(int, input().split())
	print((f[y] - f[x - 1]) % p)