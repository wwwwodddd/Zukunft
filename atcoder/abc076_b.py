n = input()
k = input()
z = 1
for i in range(n):
	z = min(2 * z, z + k)
print z