n = int(input())
a = [0] + list(map(int, input().split()))
b = [0] + list(map(int, input().split()))
for i in range(1, n + 1):
	a[i] -= b[i]
	a[i] += a[i - 1]
z = 0
for i in range(n + 1):
	if a[i] == 0:
		z = i
print(z)