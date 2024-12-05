n = int(input())
a = list(map(int, input().split()))
z = 0
for i in range(1, n):
	z = max(z, abs(a[i] - a[i - 1]))
print(z)