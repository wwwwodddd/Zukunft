a = [input() for i in range(5)]
x, y = map(int, input().split())
x -= 1
y -= 1
a[x], a[y] = a[y], a[x]
for i in range(5):
	print(a[i])