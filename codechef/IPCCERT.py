n, m, k = map(int, input().split())
z = 0
for i in range(n):
	a = list(map(int, input().split()))
	if sum(a[:-1]) >= m and a[-1] <= 10:
		z += 1
print(z)