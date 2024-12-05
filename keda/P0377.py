a = b = 0
for i in range(1, 1001):
	if bin(i).count('1') > bin(i).count('0') - 1:
		a += 1
	else:
		b += 1
print(a, b)