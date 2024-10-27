n, d = map(int, input().split())
a = list(map(int, input().split()))
j = 0
z = 0
for i in range(n):
	while a[i] - a[j] > d:
		j += 1
	z += (i - j) * (i - j - 1) // 2
print(z)
