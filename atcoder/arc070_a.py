n = input() * 2
a = int(n ** 0.5)
if a * (a + 1) < n:
	a += 1
print a