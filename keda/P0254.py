n = int(input())
s, _ = map(int, input().split())
D = []
for i in range(n):
	x, y = map(int, input().split())
	D.append((x * y, x, y))
D.sort()
z = 0
for i in range(n):
	z = max(z, s // D[i][2])
	s *= D[i][1]
print(z)