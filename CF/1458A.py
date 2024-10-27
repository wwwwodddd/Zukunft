import math
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
z = 0
for i in range(1, n):
	z = math.gcd(z, a[i] - a[0])
for i in range(m):
	print(math.gcd(z, a[0] + b[i]), end=' ')