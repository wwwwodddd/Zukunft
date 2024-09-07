n = int(input())
f = g = 0
for i in range(n):
	x = int(input())
	f, g = max(f, g + x), f
print(f)