input()
for i in map(int, input().split()):
	z = 15
	c = 0
	while i:
		j = i
		t = 0
		while j != 0:
			t += 1
			j = j * 2 % 32768
		z = min(z, c + t)
		c += i & -i
		i = (i + (i & -i)) % 32768
	z = min(z, c)
	print(z, end=' ')