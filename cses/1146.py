n = int(input()) + 1
z = 0
for i in range(50):
	t = 1 << i
	z += n // (2 * t) * t
	z += max(n % (2 * t) - t, 0)
print(z)