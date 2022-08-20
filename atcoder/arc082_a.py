n = int(input())
c = {}
for i in map(int, input().split()):
	c[i] = c.get(i, 0) + 1
z = 0
for i in range(100000):
	z = max(z, c.get(i - 1, 0) + c.get(i, 0) + c.get(i + 1, 0))
print(z)