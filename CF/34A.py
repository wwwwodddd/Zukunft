n = int(input())
a = list(map(int, input().split()))
z = 0
for i in range(n):
	if abs(a[z] - a[z - 1]) > abs(a[i] - a[i - 1]):
		z = i
print(z + 1, (z - 1) % n + 1)