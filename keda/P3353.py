n = int(input())
a = list(map(int, input().split()))
z = [0 for i in range(n)]
for i in range(1, n):
	if a[i - 1] > a[i]:
		z[i - 1] ^= 1
		z[i] ^= 1
print(*z)