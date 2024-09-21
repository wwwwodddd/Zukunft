n, m = map(int, input().split())
p = 1000000007
n -= 1
m += n
x = 1
y = 1
for i in range(n):
	x = x * (m - i) % p
	y = y * (i + 1) % p
print(x * pow(y, p - 2, p) % p)