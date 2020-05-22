l = input()
k = 0
while 2 ** (k + 1) <= l:
	k += 1
n = k + 1
e = []
for i in range(k):
	e.append((i + 1, i + 2, 0))
	e.append((i + 1, i + 2, 2 ** i))

for i in range(k):
	if l >> i & 1:
		e.append((i + 1, n, (l - 1) >> (i + 1) << (i + 1)))

print n, len(e)
for x, y, z in e:
	print x, y, z