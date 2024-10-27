n, m, k = map(int, input().split())
a = sorted(map(int, input().split()))
b = sorted(map(int, input().split()))
i = 0
j = 0
z = 0
while i < len(a) and j < len(b):
	if abs(a[i] - b[j]) <= k:
		z += 1
		i += 1
		j += 1
	elif a[i] < b[j]:
		i += 1
	else:
		j += 1
print(z)