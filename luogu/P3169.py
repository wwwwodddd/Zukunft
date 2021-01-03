n = int(input())
t = int(input())
m = int(input())
z = 0
c = 1
a = (pow(1234, m, 3389) * 209 - 208) % 3389
for i in range(n - m + 1):
	z += a * c
	c = c * (m + i + 1) // (i + 1) * t
	a = (a * 1234 + 2289) % 3389
print(z)