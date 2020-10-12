n, m = map(int, input().split())
x, y = 1, 1
for i in range(m - n):
	x, y = y, x + y
print(x)