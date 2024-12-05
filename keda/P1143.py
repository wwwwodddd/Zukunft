n = int(input())
a = list(map(int, input().split()))
z = 0
for i in range(n):
	if abs(a[z] - a[z - 1]) > abs(a[i] - a[i - 1]):
		z = i
print(abs(a[z] - a[z - 1]))
