import math
n, m = map(int, input().split())
x = 1
y = 1
for i in range(1, m):
	x *= i
	y *= i + n
x, y = y - x, x * y * (m - 1)
g = math.gcd(x, y)
x //= g
y //= g
print(x)
print(y)