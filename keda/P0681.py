n = int(input())
z = 0
if n & 1:
	for i in range(2, n, 2):
		z += i
else:
	for i in range(1, n + 1):
		if n % i == 0:
			z += i
print(z)