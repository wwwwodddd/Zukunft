n, k, p = map(int, input().split())
z = ''
def F(n, k, x):
	if k == 0:
		return '.'
	if n % 2 == 1:
		if x == n:
			return 'X'
		return F(n - 1, k - 1, x)
	if x % 2 == 0:
		if (n - x) // 2 + 1 <= k:
			return 'X'
		else:
			return '.'
	else:
		if (n - x + 1) // 2 + n // 2 <= k:
			return 'X'
		else:
			return '.'

for i in range(p):
	x = int(input())
	z += F(n, k, x)
print(z)
