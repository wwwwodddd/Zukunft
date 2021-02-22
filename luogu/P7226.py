n = int(input())
x = 0
for i in range(n):
	p = int(input())
	x += (p // 10) ** (p % 10)
print(x)