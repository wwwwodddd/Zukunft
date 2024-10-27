for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	c = sum(i % 2 for i in a)
	z = [1 << i for i in range(29, -1, -1)]
	if c == 0 or c == n:
		if c == 0:
			z.append(1)
		print(len(z))
		print(*z)
	else:
		print(-1)