import math
input()
z = 0
for i in map(int,input().split()):
	z = math.gcd(z, i)
print(z)