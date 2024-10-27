n, x = map(int, input().split())
p = sorted(map(int, input().split()))
i = 0
j = n - 1
z = 0
while i <= j:
	if i < j and p[i] + p[j] <= x:
		i += 1
		j -= 1
		z += 1
	else:
		j -= 1
		z += 1
print(z)