z = 0
for i in range(1, int(input()) + 1):
	if i % 5 == 0 and '5' in str(i):
		z += 1
print(z)