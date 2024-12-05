n = int(input())
for i in (list(range(n)) + list(range(n - 2, -1, -1))):
	print(' ' * i + ''.join(map(chr, list(range(65 + i, 65 + n)) + list(range(65 + n - 2, 64 + i, -1)))))