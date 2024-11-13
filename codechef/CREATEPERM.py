for t in range(int(input())):
	n = int(input())
	a = []
	for i in range(n):
		if i & 1:
			a.append((n + 1) // 2 + i // 2 + 1)
		else:
			a.append(i // 2 + 1)
	print(*a)