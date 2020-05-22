a = input()
z, l, r = a * a, a * a, a * a + 2 * a
while l <= r:
	z, l, r = l, (l + 99) / 100, r / 100
print z