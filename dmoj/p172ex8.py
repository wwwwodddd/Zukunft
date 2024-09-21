c = {}
while True:
	x = int(input())
	if x == -1:
		break
	if x not in c:
		c[x] = 0
	c[x] += 1
m = max(c.values())
z = sorted([i for i in c if c[i] == m])
for i in z:
	print(i)
