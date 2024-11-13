n = int(input())
a = [int(input())for i in range(n)]
z = 0
for i in range(n // 2):
	if a[i] == a[i + n // 2]:
		z += 2
print(z)