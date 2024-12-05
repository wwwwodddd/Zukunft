z = 0
for i in range(1, int(input()) + 1):
	if str(i) == str(i)[::-1]:
		z += 1
print(z)