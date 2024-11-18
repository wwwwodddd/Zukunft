n = int(input())
a = list(map(int, input().split()))
def F(x, y):
	z = 0
	for i in range(n):
		d = abs(a[i] - x - y * i)
		if d <= 1:
			z += d
		else:
			return n + 1
	return z
z = n + 1
if n == 1:
	z = 0
else:
	for i in range(a[0] - 1, a[0] + 2):
		for j in range(a[1] - 1, a[1] + 2):
			z = min(z, F(i, j - i))
if z > n:
	z = -1
print(z)