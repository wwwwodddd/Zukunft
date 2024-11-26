for t in range(int(input())):
	p, q = map(int, input().split())
	print(['Bob', 'Alice'][(p + q) % 4 < 2])
