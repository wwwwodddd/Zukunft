m, t = input().split()
z = m = int(m)
for i in range(1, m + 1):
	if t in str(i):
		z -= 1
print(z)