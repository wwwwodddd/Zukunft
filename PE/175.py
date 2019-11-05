n = 1000
f = [0 for i in range(n + 1)]
f[0] = 1

i = 1
while i <= n:
	for j in range(i, n + 1)[::-1]:
		f[j] += f[j - i]
		if j >= 2 * i:
			f[j] += f[j - 2 * i]
	i *= 2

def F(x, y):
	a = []
	while True:
		if x == 1 and y == 1:
			a.append((1, 1))
			return a
		if x > y:
			a.append((1, (x - 1) / y))
			x, y = (x - 1) % y + 1, y
		else:
			a.append((0, (y - 1) / x))
			x, y = x, (y - 1) % x + 1

y = 123456789
x = 987654321
def gcd(x, y):
	if y > 0:
		return gcd(y, x % y)
	return x
g = gcd(x, y)
x /= g
y /= g
print F(x, y)

for i in range(n):
	if f[i] == x and f[i + 1] == y:
		print i + 1