for t in range(int(input())):
	print(['NO', 'YES'][0 < sum(int(i) % 2 for i in input().split()) < 3])
