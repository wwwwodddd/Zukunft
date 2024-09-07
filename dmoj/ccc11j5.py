n = int(input())
a = [[] for i in range(n + 1)]
for i in range(1, n):
	x = int(input())
	a[x].append(i)
def F(x):
	z = 1
	for i in a[x]:
		z *= F(i) + 1
	return z
print(F(n))