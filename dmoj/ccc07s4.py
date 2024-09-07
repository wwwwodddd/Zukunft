n = int(input())
a = []
while True:
	x, y = map(int, input().split())
	if x == 0 and y == 0:
		break
	a.append((x, y))
a.sort()
f = [0 for i in range(n + 1)]
f[1] = 1
for x, y in a:
	f[y] += f[x]
print(f[n])