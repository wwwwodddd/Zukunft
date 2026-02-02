a, b = input().split()
z = max((int(a) + 499) // 500, 2) * 4
if b == 'y':
	z += 5
print(z)