n = int(input())
z = 1 % (n + 1)
for i in range(1, n + 1):
	z = z * i % (n + 1)
print(['NO', 'YES'][z == 0])