for t in range(int(input())):
	n = int(input())
	z = 0
	while (z + 1) * (z + 2) // 2 <= n:
		z += 1
	print(z)