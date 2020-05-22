a = [input() for i in range(input())] + [0]
s = sum(a)
z = 0
for i in a:
	if (s - i) % 10 > 0:
		z = max(z, s - i)
print z