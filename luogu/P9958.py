n = int(input())
a = [0, 1, 2, 3]
c = [0, 0, 0, 0]
for i in range(n):
	x, y, z = map(int, input().split())
	a[x], a[y] = a[y], a[x]
	c[a[z]] += 1
print(max(c))