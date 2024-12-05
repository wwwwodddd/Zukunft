n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
z = 0
for x, y in zip(a, b):
	z += x * y
print(z)