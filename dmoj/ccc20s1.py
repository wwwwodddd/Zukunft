n = int(input())
a = []
for i in range(n):
	x, y = map(int, input().split())
	a.append((x, y))
a.sort()
z = 0
for i in range(1, len(a)):
	z = max(z, abs(a[i][1] - a[i-1][1]) / (a[i][0] - a[i-1][0]))
print(z)