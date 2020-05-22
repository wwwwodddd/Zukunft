n, x = map(int, raw_input().split())
z = n
y = n - x
while y > 0:
	z += x / y * y * 2
	x, y = y, x % y
print z - x