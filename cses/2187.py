p = 1000000007
n = int(input())
if n % 2:
	print(0)
	exit()
n //= 2
s = input()
x = 0
y = 0
for i in s:
	if i == '(':
		x += 1
	else:
		y += 1
	if x < y:
		print(0)
		exit()
def C(n, m):
	if m < 0 or m > n:
		return 0
	x = 1
	y = 1
	for i in range(m):
		x = x * (n - i) % p
		y = y * (i + 1) % p
	return x * pow(y, p - 2, p) % p
print((C(n - x + n - y, n - x) - C(n - x + n - y, n - y + 1)) % p)
