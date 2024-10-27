p = 1000000007
m, n = map(int, input().split())
s = list(map(int, input().split()))
l = list(map(int, input().split()))
a = [[0, 0], [0, 0]]
a[0][0] = s[0]
a[0][1] = l[0]
b = [[0, 0], [0, 0]]
for i in range(m):
	b[0][0] = (b[0][0] + (s[i] + l[i]) * s[i]) % p
	b[0][1] = (b[0][1] + (s[i] + l[i]) * l[i]) % p
	b[1][0] = (b[1][0] + s[i] * s[i]) % p
	b[1][1] = (b[1][1] + s[i] * l[i]) % p
def mul(a, b):
	c = [[0, 0], [0, 0]]
	c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % p
	c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % p
	c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % p
	c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % p
	return c
n -= 1
while n > 0:
	if n & 1:
		a = mul(a, b)
	b = mul(b, b)
	n //= 2
print((a[0][0] * (sum(s) + sum(l)) + a[0][1] * sum(s)) % p)