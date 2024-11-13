for t in range(int(input())):
	p, l = map(int, input().split())
	print(['NO', 'YES'][l * 4 >= p * 3])