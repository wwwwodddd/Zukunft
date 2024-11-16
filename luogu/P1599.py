n = int(input())
z = n
c = 0
s = 0
for i in range(n):
	s += int(input())
	if s < 0:
		c += 2
	else:
		z += c
		c = 0
print(z)