p = 1000000007
t = int(input())
for tt in range(t):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	m = n - k
	x = sum(a[k:]) * ((m + 1) // 2) * pow(m, p - 2, p) % p
	y = sum(a[k:]) * (m // 2) * pow(m, p - 2, p) % p
	x += sum(a[:k]) * ((m + 2) // 2) * pow(m + 1, p - 2, p) % p
	y += sum(a[:k]) * ((m + 1) // 2) * pow(m + 1, p - 2, p) % p
	print(x % p, y % p)