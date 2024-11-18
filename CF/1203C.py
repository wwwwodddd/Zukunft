import math
n = int(input())
z = 0
c = 0
for i in map(int, input().split()):
	z = math.gcd(z, i)
i = 1
while i * i < z:
	if z % i == 0:
		c += 2
	i += 1
if i * i == z:
	c += 1
print(c)