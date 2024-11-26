for t in range(int(input())):
	print(['Yes', 'No'][sum(map(int, input().split())) % 2])