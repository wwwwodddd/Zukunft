n = int(input())
a = []
for i in range(n):
	a.append(set(input().split()[2:]))
z = 0
for i in range(n):
	for j in range(i):
		z = max(z, len(a[i] & a[j]))
print(z + 1)