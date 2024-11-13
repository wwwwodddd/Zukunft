n = int(input())
z = 0
while n > 0:
	n -= sum(map(int, str(n)))
	z += 1
print(z)