n, m = map(int, input().split())
a = sorted(map(int, input().split()))
i = 0
j = n - 1
z = 0
while i <= j:
	if a[i] + a[j] <= m:
		i += 1
	z += 1
	j -= 1
print(z)