n = int(input())
print(n)
for i in range(0, n, 2):
	print('0' * (i + 1) + '1' * (n - i - 1))
	print('1' * (i + 2) + '0' * (n - i - 2))
