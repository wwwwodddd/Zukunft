n = int(input())
x = ''
y = 0
for i in range(n):
	a, b = input().split()
	b = int(b)
	if y < b:
		x = a
		y = b
print(x, y)