p = int(input())
s = n = int(input())
r = int(input())
z = 0
while s <= p:
	n *= r
	s += n
	z += 1
print(z)