for t in range(int(input())):
	print(['IN', 'OUT'][sum(map(int, input().split())) > 0])
