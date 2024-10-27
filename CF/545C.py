n = int(input())
a = []
for i in range(n):
	x, h = map(int, input().split())
	a.append((x, h))
z = 1
p = a[0][0]
for i in range(1, n):
	if a[i][0] - a[i][1] > p:
		z += 1
		p = a[i][0]
	elif i == n - 1 or a[i][0] + a[i][1] < a[i + 1][0]:
		z += 1
		p = a[i][0] + a[i][1]
	else:
		p = a[i][0]
print(z)