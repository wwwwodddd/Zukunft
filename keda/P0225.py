n = int(input())
z = 0
c = 0
l = 0
for i in map(int, input().split()):
	if l != i:
		l = i
		c = 0
	c += 1
	z = max(z, c)
print(z)