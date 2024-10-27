import math
d0 = d1 = 0
input()
for i in map(int, input().split()):
	d0, d1 = math.gcd(d0, i), math.lcm(d0, math.gcd(d1, i))
print(d1)