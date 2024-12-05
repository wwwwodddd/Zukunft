n = int(input())
a = list(map(int, input().split()))
z = 0
for i in range(n):
	z += a[i] * max(n - i - 1, i)
print(z)