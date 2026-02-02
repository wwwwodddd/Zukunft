n = int(input())
a, b, c = 0, 0, 0
for i in range(n):
	x, y, z = map(int, input().split())
	a += x
	b += y
	c += z
print(a, b, c, a + b + c)