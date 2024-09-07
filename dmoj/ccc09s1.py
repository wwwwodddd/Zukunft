a = int(input())
b = int(input())
z = 0
for i in range(1, 30):
	if a <= i ** 6 <= b:
		z += 1
print(z)