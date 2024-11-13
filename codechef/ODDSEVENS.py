for t in range(int(input())):
	print(['Bob', 'Alice'][sum(map(int, input().split())) % 2])