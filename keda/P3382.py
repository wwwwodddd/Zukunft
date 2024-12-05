n = int(input())
z = 0
c = 0
l = 0
for i in map(int, input().split()):
	if l < i:
		c += 1
	else:
		c = 1
	l = i
	z = max(z, c)
print(z)