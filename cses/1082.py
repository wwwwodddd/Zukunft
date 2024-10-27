n = int(input())
i = 1
z = 0
while i <= n:
	d = n // i
	j = n // d
	z += (i + j) * (j - i + 1) * d // 2
	i = j + 1
print(z % 1000000007)