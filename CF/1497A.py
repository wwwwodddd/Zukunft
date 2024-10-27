for t in range(int(input())):
	n = int(input())
	a = set()
	b = []
	for i in map(int, input().split()):
		if i in a:
			b.append(i)
		else:
			a.add(i)
	print(*sorted(a), *b)