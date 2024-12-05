x, a, b = map(int, input().split())
z = 0
for i in range(1, x // b + 1):
	if x >= i * b and (x - i * b) % a == 0 and (x - i * b) > 0:
		z += 1
print(z)