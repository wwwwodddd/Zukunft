for t in range(int(input())):
	print(['NO', 'YES'][sum(map(int, input().split())) > 3])
