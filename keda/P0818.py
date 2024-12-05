while True:
	n = int(input())
	if n == 0:
		break
	for i in range(n):
		print(*[2 ** (i + j) for j in range(n)])
	print()