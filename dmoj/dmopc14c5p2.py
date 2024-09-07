n = int(input())
z = 0
for i in range(n):
	x, y = map(int, input().split())
	z = max(z, y - x)
print(z)