n = int(input())
a = sorted((map(int, input().split())))
y = -1
z = 0
for i in range(1, n + 1):
	if z <= i * a[-i]:
		z = i * a[-i]
		y = a[-i]
print(z, y)