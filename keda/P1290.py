n = int(input())
a = list(map(int, input().split()))
t = int(input())
z = 0
for i in range(n):
	for j in range(i + 1, n):
		for k in range(j + 1, n):
			if a[j] - a[i] == t and a[k] - a[j] == t:
				z += 1
print(z)