n = int(input())
a = sorted([list(map(int, input().split())) for i in range(n)])
z = 0
e = -1e18
for x, y in a:
	if e <= x:
		e = y
		z += 1
	else:
		e = min(e, y)
print(z)
