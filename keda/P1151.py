n = int(input())
a = list(map(int, input().split()))
z = 0
for i in range(1, n - 1):
	if a[i - 1] > a[i] < a[i + 1] or a[i - 1] < a[i] > a[i + 1]:
		z += 1
print(z)
