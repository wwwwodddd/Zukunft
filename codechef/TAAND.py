n = int(input())
a = [int(input()) for i in range(n)]
z = 0
for i in range(30)[::-1]:
	c = sum(j >> i & 1 for j in a)
	if c > 1:
		z |= 1 << i
		a = [j for j in a if j >> i & 1]
print(z)