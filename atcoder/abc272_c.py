n = int(input())
b = []
c = []
for i in map(int, input().split()):
	if i % 2 == 0:
		b.append(i)
	else:
		c.append(i)
if len(b) < 2 and len(c) < 2:
	print('-1')
else:
	b += [-1e18, -1e18]
	c += [-1e18, -1e18]
	b.sort()
	c.sort()
	print(max(b[-1] + b[-2], c[-1] + c[-2]))
